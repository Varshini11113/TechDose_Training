class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_diag = 0
        max_rec = 0
        for rec in dimensions:
            length = rec[0]
            width = rec[1]
            diag = (length*length) + (width*width)
            if (diag >= max_diag):
                if diag == max_diag:
                    max_rec = max(max_rec, length*width)
                else:
                    max_diag = diag
                    max_rec = length * width
        return max_rec