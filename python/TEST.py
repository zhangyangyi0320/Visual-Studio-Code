from itertools import permutations

# 定义六个人的集合
people = ['A', 'B', 'C', 'D', 'E', 'F']

# 计算所有可能的排列
all_permutations = list(permutations(people))

# 初始化计数器
valid_permutations = 0

# 遍历所有排列，检查是否满足条件
for perm in all_permutations:
    # 计算在第一个10元钞票买票之前有多少张5元钞票
    count_5_before_first_10 = sum(1 for p in perm if p in ['A', 'B', 'C'] and perm.index(p) < perm.index('D'))
    
    # 如果第一个10元钞票买票之前至少有一张5元钞票，则继续检查
    if count_5_before_first_10 >= 1:
        # 计算在第二个10元钞票买票之前有多少张5元钞票
        count_5_before_second_10 = sum(1 for p in perm if p in ['A', 'B', 'C'] and perm.index(p) < perm.index('E'))
        
        # 如果第二个10元钞票买票之前至少有两张5元钞票，则继续检查
        if count_5_before_second_10 >= 2:
            # 计算在第三个10元钞票买票之前有多少张5元钞票
            count_5_before_third_10 = sum(1 for p in perm if p in ['A', 'B', 'C'] and perm.index(p) < perm.index('F'))
            
            # 如果第三个10元钞票买票之前至少有三张5元钞票，则这是一个有效的排列
            if count_5_before_third_10 >= 3:
                valid_permutations += 1

# 输出有效的排列数
print(valid_permutations)
