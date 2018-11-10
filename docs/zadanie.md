Úkolem je vytvořit program, který bude porovnávat dvojice trojúhelníků.

V rovině jsou zadané 2 trojúhelníky, každý trojúhelník je zadán pomocí
trojice svých vrcholů (tedy je celkem zadáno 6 vrcholů). Vrchol trojúhelníku je
souřadnice ve 2D rovině, je tedy zadán jako dvě desetinná čísla. Program tyto
souřadnice přečte ze svého vstupu a rozhodne pro jednu z následujících variant:

- zda zadané body tvoří trojúhelník (zadaná trojice bodů netvoří trojúhelník, pokud body leží na jedné přímce),
- zda jsou zadané trojúhelníky shodné,
- zda jsou zadané trojúhelníky liší, ale mají stejný obvod, nebo
- zda jsou zadané trojúhelníky zcela odlišné.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový
výstup). Za chybu považujte:

- nečíselné zadání souřadnic (neplatné desetinné číslo),
- chybějící souřadnice.

**Ukázka práce programu:**

**Trojuhelnik #1:**

**Bod A:**
0 0

**Bod B:**
5 0

**Bod C:**
2.5 3

**Trojuhelnik #2:**

**Bod A:**
4 -1

**Bod B:**
7 1.5

**Bod C:**
4 4

**Trojuhelniky jsou shodne.**

**Trojuhelnik #1:**

**Bod A:**

0 15

**Bod B:**

112 0 112 15

**Bod C:**

**Trojuhelnik #2:**

**Bod A:**

0 0

**Bod B:**

96 0

**Bod C:**

0 40

**Trojuhelniky nejsou shodne, ale maji
stejny obvod.**

**Trojuhelnik #1:**

**Bod A:**

0 0

**Bod B:**

10 0

**Bod C:**

0 10

**Trojuhelnik #2:**

**Bod A:**

-5 3

**Bod B:**

12 8

**Bod C:**

37 15

**Trojuhelnik #2 ma vetsi obvod.**

**Trojuhelnik #1:**

**Bod A:**

0 14.04

**Bod B:**

11.2 0

**Bod C:**

0 0

**Trojuhelnik #2:**

**Bod A:**

20.16 0

**Bod B:**

0 2.7

**Bod C:**

20.16 2.7

**Trojuhelniky nejsou shodne, ale maji
stejny obvod.**

**Trojuhelnik #1:**

**Bod A:**

0 0

**Bod B:**

10 0

**Bod C:**

0 10

**Trojuhelnik #2:**

**Bod A:**

0 0

**Bod B:**

10 10

**Bod C:**

15 15

**Body netvori trojuhelnik.**

**Trojuhelnik #1:**

**Bod A:**

10 0

**Bod B:**

20 1

**Bod C:**

25 1.5

**Body netvori trojuhelnik.**

**Trojuhelnik #1:**

**Bod A:**

0 0

**Bod B:**

999.990 204.330

**Bod C:**

899.991 183.897

**Body netvori trojuhelnik.**

**Trojuhelnik #1:**

**Bod A:**

1 2

**Bod B:**

3 abcd

**Nespravny vstup.**

**Poznámky:**

- Ukázkové běhy zachycují
     očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem
     (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce
     zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit
     text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za
     poslední řádkou výstupu (i za případným chybovým hlášením).
- Pro reprezentaci hodnot
     použijte desetinná čísla typu double. Nepoužívejte typ float, jeho přesnost nemusí být
     dostatečná.
- Úlohu lze vyřešit bez použití
     funkcí. Pokud ale správně použijete funkce, bude program přehlednější a
     bude se snáze ladit.
- Číselné vstupní hodnoty jsou
     zadávané tak, aby se vešly do rozsahu datového typu double. Referenční řešení si vystačí
     s číselnými typy double a int.
- Pro načítání vstupu se hodí
     funkce scanf.
- Při programování si dejte pozor
     na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který
     požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za
     chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající
     mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle
     vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných
     výstupních dat. Podívejte se na videotutoriál (materiály -&gt; cvičebnice
     -&gt; video tutoriály), jak testovací data použít a jak testování
     zautomatizovat.
- Váš program bude spouštěn v
     omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu
     referenčního řešení) a dále je omezena i velikost dostupné paměti (ale
     tato úloha by ani s jedním omezením neměla mít problém). Testovací
     prostředí dále zakazuje používat některé "nebezpečné funkce" --
     funkce pro spouštění programu, pro práci se sítí, ... Pokud jsou tyto funkce
     použité, program se nespustí.

  

- Slovní popis struktury platných vstupních dat není zcela exaktní. Proto připojujeme i formální popis vstupního jazyka v EBNF:

·        
    input      ::= { whiteSpace } coord { whiteSpace }
coord { whiteSpace } coord { whiteSpace } 

·        
                      coord {
whiteSpace } coord { whiteSpace } coord { whiteSpace } 

·        
    whiteSpace ::= ' ' | '\t' | '\n'
| '\r'

·        
    coord      ::= decimal { whiteSpace } decimal 

·        
    decimal    ::= [ '+' | '-' ] integer [ '.' integer [ (
'e' | 'E' ) [ '+' | '-' ] integer ] ]  |

·        
                   [ '+' | '-'  ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ]
integer ]

·        
    integer    ::= digit { digit }

    digit      ::= '0' | '1' | '2' | '3' | '4' | '5' |
'6' | '7' | '8' | '9'