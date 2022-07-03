/**
 * @param {number[]} nums
 * @return {number}
 */
var wiggleMaxLength = function(nums) {
    
    var valley = 1 , peak = 1;
    
    for(var i = 0; i < nums.length-1; i++){
        if(nums[i] < nums[i+1]) valley = peak + 1;
        else if (nums[i] > nums[i+1]) peak = valley + 1; 
    }
    
    return Math.max(valley, peak);
};