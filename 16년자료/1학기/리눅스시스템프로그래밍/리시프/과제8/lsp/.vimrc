     set nocompatible 

    filetype off 

    set rtp+=~/.vim/bundle/Vundle.vim 

    call vundle#begin() 

    Plugin 'gmarik/Vundle.vim' "required

    Plugin 'tpope/vim-fugitive' "required 

    call vundle#end()            

    filetype plugin indent on " Put your non-Plugin stuff after this line
     syntax enable #syntax highlighting

    set nu # add line numbers

    set smartindent # make smart indent

    set tabstop=4 # tab width as 4 (default 8)

    set shiftwidth=4 

    set expandtab
