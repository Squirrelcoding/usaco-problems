class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
    def set_left(self, x):
        self.left = x
    def set_right(self, x):
        self.right = x


def generate_trees(nums):
    res = []
    if len(nums) == 1:
        return [Node(nums[0])]

    for i in range(1, len(nums)):
        for op in ["+", "-", "*", "/"]:
            left_half = generate_trees(nums[:i])
            right_half = generate_trees(nums[i:])
            for l in left_half:
                for r in right_half:
                    current_node = Node(op)
                    current_node.set_left(l)
                    current_node.set_right(r)
                    res.append(current_node)
    return res

def evaluate_tree(tree: Node):
    if tree.val not in ["+", "-", "*", "/"]:
        return tree.val
    else:
        left = evaluate_tree(tree.left) #pyright: ignore
        right = evaluate_tree(tree.right) #pyright: ignore
        if not left or not right:
            return None
        if tree.val == "+":
            return left + right
        if tree.val == "-":
            return left - right
        if tree.val == "*":
            return left * right
        if tree.val == "/":
            return left / right

trees = generate_trees([8.0, 1.0, 1.0, 3.0])
results = []

int_max = 0

for tree in trees:
    r = evaluate_tree(tree)
    if r:
        if r.is_integer() and r <= 24:
            int_max = max(int_max, int(r))


print(int_max)
