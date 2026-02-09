./ft_otool $1 > ft_otool.output
otool -t $1 > otool.output

diff otool.output ft_otool.output
