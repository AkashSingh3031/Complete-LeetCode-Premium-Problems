<h2><a href="https://leetcode.com/problems/binary-tree-upside-down/">156. Binary Tree Upside Down</a></h2><h3>Medium</h3><hr><div><p>Given the <code>root</code> of a binary tree, turn the tree upside down and return <em>the new root</em>.</p>

<p>You can turn a binary tree upside down with the following steps:</p>

<ol>
	<li>The original left child becomes the new root.</li>
	<li>The original root becomes the new right child.</li>
	<li>The original right child becomes the new left child.</li>
</ol>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/29/main.jpg" style="width: 600px; height: 95px;">
<p>The mentioned steps are done level by level. It is <strong>guaranteed</strong> that every right node has a sibling (a left node with the same parent) and has no children.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/29/updown.jpg" style="width: 800px; height: 161px;">
<pre><strong>Input:</strong> root = [1,2,3,4,5]
<strong>Output:</strong> [4,5,2,null,null,3,1]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[0, 10]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10</code></li>
	<li>Every right node in the tree has a sibling (a left node that shares the same parent).</li>
	<li>Every right node in the tree has no children.</li>
</ul>
</div>