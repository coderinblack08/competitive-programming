# Coderinblack's Competitive Programming Collection
> 👨🏼‍💻😉 Don't judge the code

This Git Repo contains all my files that I have created over the "years" in competitive programming! Hope this can help you on you as well.

I personally use vim/vscode to write my programs and use VScode's Code Runner extension to run my c++ programs.

To let code runner run in the terminal (so that you can write to the input) add 
``` json
{
  "code-runner.runInTerminal": true
}
```

I also have a fish shell alias so i can run `run file`.

```fish
# run c++ programs
function run -d "Compiles and Run c++ program with gcc `run <name>`"
  g++ -std=c++11 -O2 $argv[1].cpp -o $argv[1] -Wall && ./$argv[1]
end
```

to your settings.json on vscode or add 
``` bash
nnoremap <C-c> :!g++ -o  %:r.out % -std=c++11<Enter>
nnoremap <C-x> :!./%:r.out
```

to your .vimrc to help you easily compile and run c++.