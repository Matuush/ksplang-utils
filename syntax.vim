syn case ignore

syn match comp "\<\(def\|end\)\>"
hi comp ctermfg=red guifg=red

syn match comment "//.*$"
syn match comment "/\*\(.\|$\|^\)*\*/"
hi comment ctermfg=darkgrey guifg=darkgrey

syn match manipulation "\<pop2\?\>"
syn match manipulation "\<l\(-swap\|roll\)\>"
syn match manipulation "\<swap\>"
hi manipulation ctermfg=yellow guifg=yellow

syn match arithmetic "\<max\>"
syn match arithmetic "\<++\>"
syn match arithmetic "\<u\>"
syn match arithmetic "\<rem\>"
syn match arithmetic "\<%\>"
syn match arithmetic "\<tetr\>"
syn match arithmetic "\<^^\>"
syn match arithmetic "\<m\>"
syn match arithmetic "\<cs\>"
syn match arithmetic "\<lensum\>"
syn match arithmetic "\<bitshift\>"
syn match arithmetic "\<and\>"
syn match arithmetic "\<sum\>"
syn match arithmetic "\<\(gc\)\?d\>"
syn match arithmetic "\<qeq\>"
syn match arithmetic "\<funkcia\>"
hi arithmetic ctermfg=lightblue guifg=cyan

syn match control_flow "\<brz\>"
syn match control_flow "\<call\>"
syn match control_flow "\<goto\>"
syn match control_flow "\<j\>"
syn match control_flow "\<rev\>"
hi control_flow ctermfg=green guifg=orange

syn match meme "\<deez\>"
syn match meme "\<spanek\>"
syn match meme "\<bulkxor\>"
syn match meme "\<praise\>"
syn match meme "\<-ff\>"
syn match meme "\<kpi\>"
hi meme ctermfg=magenta guifg=magenta

syn match constant_exp "cs cs lensum cs funkcia"
hi constant_exp ctermfg=blue guifg=blue
