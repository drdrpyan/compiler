ast node의 node type은 원소 kind에 의해 결정됨.
kind의 값은 ast.h의 6~12줄에 정의되어있음.

mknode, mkleaf는 새로운 노드를 heap에 생성하고 이의 주소를 반환한다.
mknode는 자식으로 두 피연산자 노드를 갖는 이항 연산자 노드를 heap애 생성하고 이의 주소를 반환한다.
mknode는 첫째 피연산자를 3번째 인자로 받아 연산자 노드의 자식으로 이용한다. 둘째 피연산자를 넷째 연산자로 받아 첫째 피연산자의 형제로 이용한다.

prtree는 전달받은 노드를 트리의 루트로 삼아 ast를 출력한다.
주어진 indent값만큼 들여쓰기를 하고 자기 자신의 정보를 출력한다.
그 뒤 자신의 자식에 대해 recursive call을 한다. 이 때 들여쓰기 칸 수는 1 증가시킨다.
자식에 대한 출력이 끝나고 나면 다시 자신의 형제들애 대해 recursive call을 호출한다.

expr.y에서 모든 nonterminal은 (struct _node *ptrVal)형으로 취급한다.