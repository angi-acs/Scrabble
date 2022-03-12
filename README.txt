Am creat o funcție auxiliară (setboard) pentru umplerea tablei cu puncte pe care o voi 
folosi la aproape toate task-urile, începând cu task-ul 0.
O a doua funcție auxiliară (setword) este cea care pune cuvântul la coordonatele indicate, 
așezând fiecare literă în parte (literă obținută prin pointarea către cuvânt).
La task-ul 1, prima linie primită reprezintă numărul de linii următoare pe care le voi 
primi și îl convertesc în int pentru a-l utiliza într-un for care să-mi efectueze 
următoarele operații pe fiecare linie: despart linia în 4 pointeri – primii 3 reprezintă 
coordonatele cuvântului (convertite în int pentru a putea fi utilizate), iar al 4-lea 
repezintă cuvântul propriu-zis pe care îl pun pe tablă prin funcția setword.
Urmează funcția auxiliară de scor (score) care atribuie unei variabile scorul potrivit 
fiecărei litere, apoi o returnează.
La task-ul 2 aceleași operații ca la task-ul 1, diferența fiind că voi calcula scorul 
total al fiecărui player. Încep numărătoarea de la 0 astfel încât cuvintele “pare, ca să 
zic așa, vor aparține player-ului 1, iar cele “impare” celui de-al doilea.
Funcția bonus verifică să fie îndeplinite condițiile de bonus și multiplică scorul.
Task-ul 3 l-am rezolvat asemenea celui de-al doilea, prima diferență fiind bineînțeles, 
adăugarea bonusurilor la scor, iar ce-a de-a doua apariția substring-urilor care califică 
cuvintele pentru bonus. Am reținut fiecare substring într-un vector, fiecare poziție a 
vectorului reprezentând o literă.
La task-ul 4, spre deosebire de celelalte, am adăugat un vector care reține cuvintele 
care se află deja pe tabla de joc. Pentru a adăuga un nou cuvânt, din lista words, am 
început prin a verifica dacă nu este deja folosit, dacă prima sa literă se află pe board 
(literă obținută tot printr-un pointer), dacă are loc pe tablă orizontal sau vertical 
(adică să nu se suprapună cu existentele cuvinte și nici să nu iasă din dimensiunile tablei), 
urmând așezarea efectivă. (variabila un_cuvânt am folosit-o exclusiv pentru a putea da 
break după așezarea unui singur cuvânt)
La task-ul 5, după ce am aflat scorul fiecărui player (see task3) și verificat toate 
condițiile menționate la 4, în loc să așez cuvântul, i-am calculat scorul. Dacă era mai 
mare decât al cuvântului precedent, îl salvam într-o variabilă, precum și coordonatele 
sale. Dacă scorul maxim al unui cuvânt din words adunat la scorul aferent player-ului 2 
era mai mare decât cel al player-ului 1, puneam cuvântul pe tablă pentru a câștiga jocul.
