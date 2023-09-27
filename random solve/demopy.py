import numpy as np
class TreeNode:


def __init__(self, depth=0, max_depth=None):
    self.depth = depth
    self.max_depth = max_depth
    self.feature_index = None
    self.threshold = None
    self.left = None
    self.right = None
    self.value = None
    def gini_impurity(y):
    _, counts = np.unique(y, return_counts=True)
    probabilities = counts / len(y)
    return 1 - np.sum(probabilities ** 2)


def information_gain(left_y, right_y, parent_impurity):
    total_samples = len(left_y) + len(right_y)
    left_weight = len(left_y) / total_samples
    right_weight = len(right_y) / total_samples
    weighted_impurity = left_weight * \
        gini_impurity(left_y) + right_weight * gini_impurity(right_y)
    return parent_impurity - weighted_impurity


def split_dataset(X, y, feature_index, threshold):
    left_mask = X[:, feature_index] <= threshold
    right_mask = X[:, feature_index] > threshold
    left_y, right_y = y[left_mask], y[right_mask]
    left_X, right_X = X[left_mask], X[right_mask]
    return left_X, left_y, right_X, right_y


def build_decision_tree(X, y, depth=0, max_depth=None):
    node = TreeNode(depth, max_depth)
    # Check if the node should be a leaf node (pure or reached max depth)
    if len(np.unique(y)) == 1 or (max_depth is not None and depth >= max_depth):
    node.value = np.bincount(y).argmax()  # Assign the most frequent class
    return node


num_samples, num_features = X.shape
parent_impurity = gini_impurity(y)
best_information_gain = 0
for feature_index in range(num_features):
thresholds = np.unique(X[:, feature_index])
for threshold in thresholds:
left_X, left_y, right_X, right_y = split_dataset(
    X, y, feature_index, threshold)
5
if len(left_y) == 0 or len(right_y) == 0:
continue
gain = information_gain(left_y, right_y, parent_impurity)
if gain > best_information_gain:
best_information_gain = gain
node.feature_index = feature_index
node.threshold = threshold
node.left = build_decision_tree(left_X, left_y, depth + 1, max_depth)
node.right = build_decision_tree(right_X, right_y, depth + 1, max_depth)
return node
def predict_tree(node, X):


if node.value is not None:
return node.value
if X[node.feature_index] <= node.threshold:
return predict_tree(node.left, X)
else:
return predict_tree(node.right, X)
