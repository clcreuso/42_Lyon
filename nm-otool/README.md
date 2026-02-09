# Recoding nm and otool binaries

Project make at school 42Lyon.

### Installing for MAC OSX

Just need git (normaly you have it ^^)

```
git clone https://github.com/clcreuso/Nm-otool.git
cd Nm-otool/Rendu
make
```

Use *ft_nm* for *nm* command.
Use *ft_otool* for *otool -t* command.

## Running the tests

The test print diff. If the output of ft_nm have a diff than nm output. 

```
sh Scripts/diff_nm.sh path/of/binary
sh Scripts/diff_otool.sh path/of/binary
```

## Authors

* **Clément CREUSOT** - *Initial work* - [Clcreuso](https://github.com/clcreuso)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
