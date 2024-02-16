# ksplang-utils
Utility na programování v ksplangu - nejlepším programovacím jazyce

## ksplang preprocesor
C++ program s následujícími featurami
- Smaže vše na každém řádku od '//' včetně
    - Což efektivně znamená možnost psát komentáře při implementaci
- Uloží si všechny bloky počínající 'def keyword' a končící 'end' a recykluje je
    - 'def' a 'end' musí být na začátku řádku
    - syntax: 
        > `def name`\
        > `blok kódu`\
        > `end`
    - Každý další výskyt jména funkce nahradí blokem kódu
        - Volání funkce na začátku samostatného řádku

## ksplang vim syntax highlighting
Pár regexů matchujících jednotlivé instrukce ksplangu pro textový editor Vim
    - Obarvování instrukcí tak nějak, jak mně se to líbilo
    - `def` a `end` jsou červeně
    - fn_name jsou zeleně pro barevná jména funkcí
