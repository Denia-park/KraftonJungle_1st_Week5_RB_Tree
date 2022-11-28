# Red-Black Tree Src

## 필요 기능 구현 목록

### 구현 완료
-  new_tree(): RB tree 구조체 생성
-  print_tree_inorder(tree) : tree 내부에서 현재 노드값이 어떻게 배열되어 있는지 중위순회로 print 한다.
-  print_node_inorder(ptr) : print_tree_inorder 내부에서 사용되는 메서드이며 노드의 ptr을 받아서 중위순회로 탐색하고 node의 값을 출력한다. [※Nil 노드의 값을 출력하지 않음]
-  makeNewNode(key) : key 값을 가진 노드를 만들어주는 함수
-  makeNilNode(ptr) : NIL 노드를 만들어주는 함수 (key = NULL)
-  left_rotate(tree, ptr): tree 내부에서 노드의 ptr 를 기준으로 왼쪽 회전
-  right_rotate(tree, ptr): tree 내부에서 노드의 ptr 를 기준으로 오른쪽 회전
-  tree_insert(tree, key) : key 추가
-  tree_insert_fixup(tree, ptr) : RB tree의 특성을 만족함을 보장하기 위해 보조 프로시저로 해당 메서드를 수행해 노드의 색깔을 바꾸고 회전을 수행한다. 
-  fixupLeftCase(tree, ptr): tree_insert_fixup 내부에서 위치에 따라 Case가 달라지는데 코드 가독성을 위해서 메서드 분리 , 내부적으로 Case 1 2 3 으로 다시 나뉜다.
-  fixupRightCase(tree, ptr): tree_insert_fixup 내부에서 위치에 따라 Case가 달라지는데 코드 가독성을 위해서 메서드 분리 , 내부적으로 Case 1 2 3 으로 다시 나뉜다.
-  tree_find(tree, key) : key 값 검색
-  tree_min(tree): RB tree 중 최소 값을 가진 node pointer 반환
-  tree_max(tree): 최대값을 가진 node pointer 반환
-  tree_delete_node(tree, key): RB tree 내부에서 key를 찾고 해당 key를 가지는 node를 삭제하고 메모리 반환
    -  아래 메서드를 사용
        -  tree_find(tree, key): key 값 검색
        -  tree_erase(tree, ptr): RB tree 내부의 ptr로 지정된 node를 삭제하고 메모리 반환
-  tree_to_array(tree, array, n) : RB tree의 내용을 key 순서대로 주어진 array로 변환
-  delete_tree(tree): RB tree 구조체가 차지했던 메모리 반환