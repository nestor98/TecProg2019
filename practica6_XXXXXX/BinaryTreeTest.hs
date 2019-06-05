import BinaryTree

testTree = tree "R" (tree "HI" (leaf "NII") (leaf "NID")) (tree "HD" (leaf "NDI") (leaf "NDD"))

--treeVacio::BinTree Int

main = do
    --testTree = tree "R" (tree "HI" (leaf "NII") (leaf "NID")) (tree "HD" (leaf "NDI") (leaf "NDD"))
    print (testTree)
    print (empty::(BinTree Int))
    print (size testTree)
    print (preorder testTree)
    print $ size testTree
    print $ preorder testTree
    print $ postorder testTree
    print $ inorder testTree
    print $ inorder $ foldl add empty [3, 2, 5, 1, 4]
    print $ between (foldl add empty [3, 2, 2, 5, 1, 4, 4]) 2 4
    print $ inorder $ foldl add empty ["Juan", "Pedro", "Adolfo", "Diego"]
    print $ between (foldl add empty [1, 2, 3, 4, 5, 6, 7,8,9,10,100,200]) 2 25
    print $ (foldl add empty [3, 2, 2, 5, 1, 4, 4])

    print (add testTree "ZZ")