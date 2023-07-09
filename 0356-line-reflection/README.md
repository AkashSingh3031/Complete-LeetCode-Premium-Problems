<h2><a href="https://leetcode.com/problems/line-reflection">356. Line Reflection</a></h2><h3>Medium</h3><hr><p>Given <code>n</code> points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.</p>

<p>In other words, answer whether or not if there exists a line that after reflecting all points over the given line, the original points&#39; set is the same as the reflected ones.</p>

<p><strong>Note</strong> that there can be repeated points.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/356_example_1.PNG" style="width: 389px; height: 340px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[-1,1]]
<strong>Output:</strong> true
<strong>Explanation:</strong> We can choose the line x = 0.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/356_example_2.PNG" style="width: 300px; height: 294px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[-1,-1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> We can&#39;t choose a line.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup> &lt;= points[i][j] &lt;= 10<sup>8</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do better than <code>O(n<sup>2</sup>)</code>?</p>
