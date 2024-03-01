/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    var str1 = s.split(" ");
    return str1.reverse().filter(w => w != "").join(" ");
};