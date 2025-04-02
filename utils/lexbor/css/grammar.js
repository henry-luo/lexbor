// const {grammar} = require('tree-sitter-cli/grammar');

module.exports = grammar({
  name: 'css_grammar',

  // Add explicit conflicts declaration to handle the ambiguity
  conflicts: $ => [
    [$.expression, $.sequence],
    // [$.alternation]  // Add conflict declaration for alternation rule
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
      $.rule_name,
      '=',
      $.expression
    ),

    rule_name: $ => /<[a-zA-Z0-9-_]+>/,

    expression: $ => choice(
      prec.left(2, $.alternation),    // Higher precedence for alternation
      prec.left(2, $.combinatorial),  // Higher precedence for combinatorial
      prec.left(1, $.sequence),       // Middle precedence for sequence
      prec(0, $.atom)                 // Lowest precedence for atom
    ),

    alternation: $ => prec.left(seq(
      $.expression,
      '|',
      $.expression
    )),

    combinatorial: $ => prec.left(seq(
      $.expression,
      '&&',
      $.expression
    )),

    sequence: $ => repeat1($.atom),

    atom: $ => choice(
      $.literal,
      $.reference,
      $.group,
      $.repetition,
      $.optional
    ),

    literal: $ => /[a-zA-Z0-9-_]+/,

    reference: $ => seq(
      '<',
      field('name', /[a-zA-Z0-9-_]+/),
      optional(repeat1(seq(
        ' ',
        field('constraint_name', /[a-zA-Z0-9-_]+/),
        '=',
        field('constraint_value', /-?[0-9]+(\.[0-9]+)?/)
      ))),
      '>',
      optional(seq(
        '^',
        field('permission', /[A-Z]+/)
      ))
    ),

    group: $ => choice(
      seq('[', $.expression, ']'),
      seq('(', $.expression, ')')
    ),

    repetition: $ => choice(
      seq($.atom, '*'),
      seq($.atom, '+'),
      seq($.atom, '#'),
      seq(
        $.atom,
        '{',
        field('min', /[0-9]+/),
        optional(seq(',', optional(field('max', /[0-9]+/)))),
        '}'
      )
    ),

    optional: $ => seq(
      $.atom,
      '?'
    )
  }
});
