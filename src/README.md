# Red-Black Tree Src

## 필요 기능 구현 목록

### 구현 완료
-  new_tree(): RB tree 구조체 생성
---
### 구현 필요
-  tree_insert(tree, key) : key 추가
-  tree_find(tree, key) : key 값 검색
-  tree_min(tree): RB tree 중 최소 값을 가진 node pointer 반환
-  tree_max(tree): 최대값을 가진 node pointer 반환
-  tree_erase(tree, ptr): RB tree 내부의 ptr로 지정된 node를 삭제하고 메모리 반환
-  delete_tree(tree): RB tree 구조체가 차지했던 메모리 반환
-  tree_to_array(tree, array, n) : RB tree의 내용을 key 순서대로 주어진 array로 변환