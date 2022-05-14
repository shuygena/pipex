# Download & Compile
Clone repository:
```
git clone https://github.com/shuygena/pipex.git
```
Go to directory:  
```
cd pipex
```
For compile programm run:  
```
make bonus
```

# How to use
For using redirection with < and > run:
```
./pipex file1 command1 command2 ... comandN file2
```
Example:
```
./pipex main.c "grep if" cat outputfile.txt
```
For using redirection with << adn >> run:
```
./pipex here_doc command1 KEY command2 ... commandN file2
```
Example:
```
./pipex here_doc "ls -la" lol "grep .c" "cat -e" outputfile.txt
```
