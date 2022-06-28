# Root to leaf path sum
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a binary tree and an integer S, check whether there is root to leaf path with its sum as S.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
Tree = 
            1
          /   \
        2      3
S = 2</span>

<span style="font-size:18px"><strong>Output: </strong>0</span>

<span style="font-size:18px"><strong>Explanation:</strong>
There is no root to leaf path with sum 2.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
Tree = 
            1
          /   \
        2      3
S = 4</span>

<span style="font-size:18px"><strong>Output:</strong> 1</span>

<span style="font-size:18px"><strong>Explanation:</strong>
The sum of path from leaf node 3 to root 1 is 4.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You dont need to read input or print anything. Complete the function<strong> hasPathSum()</strong> which takes <strong>root </strong>node and target sum <strong>S</strong> as input parameter and returns true if path exists otherwise it returns false.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(height of tree)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10^4<br>
1 ≤ S ≤ 10^6</span></p>
 <p></p>
            </div>