Nonterminal은 Line, Expr, Term, Factor, Num을 사용하였다.
Expr단계에서 +, -를 처리하였다.
Term단계에서 *, /, %를 처리하였다.
Factor단계에서 power연산을 처리하였다.
Factor단계에서 'Factor -> Num ^ Factor'가 'Factor -> Num'보다 먼저 처리되도록 하여 '^'연산이 right associative하도록 하였다.
( Expr )을 처리하기 위해 Factor와 terminal사이에 Num을 추가하였다.