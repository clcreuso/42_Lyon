./ft_nm $1 > ft_nm.output
nm $1 > nm.output

diff nm.output ft_nm.output
