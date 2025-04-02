module.exports = grammar({
  name: 'css_grammar',

  // Simplified conflict resolution - focusing on major rule conflicts only
  conflicts: $ => [
    [$.expression, $.sequence],
    // np[$.alternation, $.combinatorial]
  ],

  // Define token types explicitly for better syntax highlighting
  extras: $ => [
    $.comment,
    /\s/
  ],

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.rule_definition,
      $.comment
    ),

    comment: $ => choice(
      seq('//', /.*/),
      seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')
    ),

    rule_definition: $ => seq(
      field('name', $.rule_name),
      '=',
      field('value', $.expression)
    ),

    rule_name: $ => /<[a-zA-Z0-9-_]+>/,

    // Expression hierarchy with clear precedence
    expression: $ => choice(
      prec.left(3, $.alternation),
      prec.left(2, $.combinatorial),
      prec.left(1, $.sequence),
      prec(0, $.atom)
    ),

    alternation: $ => prec.left(seq(
      field('left', $.expression),
      '|',
      field('right', $.expression)
    )),

    combinatorial: $ => prec.left(seq(
      field('left', $.expression),
      '&&',
      field('right', $.expression)
    )),

    // Simplified sequence that doesn't handle permissions directly
    sequence: $ => prec.right(seq(
      repeat1($.atom)
    )),

    // Permission becomes a standalone atom, not part of sequence or reference
    atom: $ => choice(
      $.literal,
      $.reference,
      $.permission,
      $.group,
      $.repetition,
      $.optional,
      $.function_call
    ),

    literal: $ => token(choice(
      /[a-zA-Z0-9-_]+/,
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'")
    )),

    // Simplified reference with no permission handling
    reference: $ => seq(
      '<',
      field('name', /[a-zA-Z0-9-_]+/),
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

    // Permissions as a separate atom type (not part of references or sequences)
    permission: $ => token(seq(
      '^',
      /[A-Z]+/
    )),

    group: $ => choice(
      seq('[', field('content', $.expression), ']'),
      seq('(', field('content', $.expression), ')')
    ),

    repetition: $ => choice(
      seq(field('element', $.atom), '*'),
      seq(field('element', $.atom), '+'),
      seq(field('element', $.atom), '#'),
      seq(
        field('element', $.atom),
        '{',
        field('min', /[0-9]+/),
        optional(seq(',', optional(field('max', /[0-9]+/)))),
        '}'
      )
    ),

    optional: $ => seq(
      field('element', $.atom),
      '?'
    ),

    function_call: $ => seq(
      field('name', /[a-zA-Z0-9-_]+/),
      '(',
      optional(field('arguments', $.expression)),
      ')'
    )
  }
});
