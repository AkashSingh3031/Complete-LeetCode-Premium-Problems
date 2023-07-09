<h2><a href="https://leetcode.com/problems/sort-transformed-array">360. Sort Transformed Array</a></h2><h3>Medium</h3><hr><p>Given a <strong>sorted</strong> integer array <code>nums</code> and three integers <code>a</code>, <code>b</code> and <code>c</code>, apply a quadratic function of the form <code>f(x) = ax<sup>2</sup> + bx + c</code> to each element <code>nums[i]</code> in the array, and return <em>the array in a sorted order</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [-4,-2,2,4], a = 1, b = 3, c = 5
<strong>Output:</strong> [3,9,15,33]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [-4,-2,2,4], a = -1, b = 3, c = 5
<strong>Output:</strong> [-23,-5,1,7]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-100 &lt;= nums[i], a, b, c &lt;= 100</code></li>
	<li><code>nums</code> is sorted in <strong>ascending</strong> order.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve it in <code>O(n)</code> time?</p>
