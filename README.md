# Coderinblack's Competitve Programming Collection
> 👨🏼‍💻😉 Don't judge the code

This Git Repo contains all my files that I have created over the "years" in competitve programming, I am also working on a standard for writting psuedocode called "half"! Hope this can help you on you as well.

I personally use vim/vscode to write my programs and use Vscode's Code Runner extension to run my c++ programs.

To let code runner run in the terminal (so that you can write to the input) add 
``` json
{
  "code-runner.runInTerminal": true
}
```
to your setttings.json on vscode or add 
``` bash
nnoremap <C-c> :!g++ -o  %:r.out % -std=c++11<Enter>
nnoremap <C-x> :!./%:r.out
```
to your .vimrc to help you easily compile and run c++.