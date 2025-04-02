module.exports = grammar({
  name: 'css_grammar',

  // Simplified conflict resolution - focusing on major rule conflicts only
  conflicts: $ => [
    [$.expression, $.sequence]
  ],

  // Define token types explicitly for better syntax highlighting
  extras: $ => [
    $.comment,
    /[ \t]+/,
    $.continuation
  ],

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.rule_definition,
      $.comment,
      $.newline
    ),

    newline: $ => /[\n\r]+([ \t]+[\n\r]+)?/,

    continuation: $ => token(/[\n\r]+[ \t]+/),

    comment: $ => choice(
      seq('//', /.*/),
      seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'),
    ),

    rule_definition: $ => seq(
      field('name', $.rule_name),
      '=',
      field('value', $.expression), 
      $.newline
    ),

    rule_name: $ => /<[a-zA-Z0-9-_]+(\(\))?>/,  // name with optional ()

    // Expression hierarchy with clear precedence
    expression: $ => choice(
      prec.left(4, $.alternation),
      prec.left(3, $.double_pipe),
      prec.left(2, $.combinatorial),
      prec.left(1, $.sequence),
      prec(0, $.atom)
    ),

    alternation: $ => prec.left(seq(
      field('left', $.expression),
      repeat1(prec.left(seq('|', field('right', $.expression)))),
      repeat(prec.left(seq($.continuation, '|', field('right', $.expression))))
    )),

    double_pipe: $ => prec.left(seq(
      field('left', $.expression),
      '||',
      field('right', $.expression)
    )),

    combinatorial: $ => prec.left(seq(
      field('left', $.expression),
      '&&',
      field('right', $.expression)
    )),

    sequence: $ => prec.left(repeat1($.atom)),

    atom: $ => choice(
      $.reference,
      $.permission,
      $.group,
      prec(1, $.function_call),
      $.repetition,
      $.option,
      prec(0, $.literal)
    ),

    /* writting literal as token gives problem to function_call parsing */ 
    literal: $ => choice(
      /[a-zA-Z0-9-_]+/,
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'"),
      '#', '/', ','
    ),

    reference: $ => seq(
      '<',
      field('name', /[a-zA-Z0-9-_]+/),
      optional(seq('(',')')),  // function name
      optional($.constraints),
      '>'
    ),

    constraints: $ => repeat1(seq(
      ' ',
      field('constraint_name', /[a-zA-Z0-9-_]+/),
      '=',
      field('constraint_value', choice(
        /-?[0-9]+(\.[0-9]+)?/,
        seq('"', /[^"]*/, '"'),
        /[a-zA-Z0-9-_]+/
      ))
    )),

    permission: $ => token(seq(
      '^',
      /[A-Z]+/
    )),

    group: $ => seq('[', field('content', $.expression), ']'),

    occurrence: $ => seq(
      '{',
      field('min', /[0-9]+/),
      optional(seq(',', optional(field('max', /[0-9]+/)))),
      '}'
    ),

    repetition: $ => prec.right(5, choice(
      seq(field('element', $.atom), '*'),
      seq(field('element', $.atom), '+'),  // '+' for 1+ repeatition separeted by space
      seq(field('element', $.atom),  '#', optional($.occurrence)), // '#' for 1+ repeatition separeted by ','
      seq(field('element', $.atom), $.occurrence)
    )),

    option: $ => seq(
      field('element', $.atom),
      '?'
    ),

    function_call: $ => seq(
      field('name', /[a-zA-Z0-9-_]+/),
      '(',
      optional(seq(
        field('first_argument', $.expression),
        repeat(seq(',', $.expression))
      )),
      ')'
    )
  }
});
