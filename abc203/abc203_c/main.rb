n, k = gets.split(" ").map(&:to_i)

friends = {}
alist = []

n.times do |i|
    a, b = gets.split(" ").map(&:to_i)
    alist << a
    if friends.has_key?(a)
        friends[a] += b;
    else
        friends[a] = b;
    end
end

now = 0

alist = alist.sort().uniq()
alist.each do |a|
    if k >= a
        k += friends[a]
    end
end

puts k