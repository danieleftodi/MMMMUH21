# Har uppdaterat uppgiften och prioriterat om i vilken ordning uppgifterna ska göras

1. ✅ Updatera ```walk.cpp``` till [kodstandarden](https://barrgroup.com/embedded-systems/books/embedded-c-coding-standard) så den blir enklare att läsa

2. ✅ Dela upp koden i följande 4 sektioner

 /\***DECLARATIONS**\*/ <br>
 /\***INIT**\*/ <br>
 /\***LOOP**\*/ <br>
 /\***FUNCTIONS**\*/ <br>
 /\***END**\*/<br>

3. ✅ Updatera<p>
  ```std::cout << "\x1B[2J\x1B[H";```<p> 
Denna "*resets terminal*" med vår clearScreen(void) från vår common_lib.cpp

4. ✅ Lägg till  ```char currentToRender[10][10] ```. 

	Gör en ny  ```drawBoard2 ``` som istället för att först skriva till skärmen först gör sin uppdateringslogik direkt på att skriva till  ```currentToRender ```.

	Först sedan när allt är skrivet (och skrivet över varandra) så ritas det som finns här upp på skärmen. 
	
	**Tips** dvs först måste hela boarden representerad i  ```currentToRender ``` "tömmas" genom att varje plats fyllas med  ```'.' ``` som representerar att ingen bandit, spelar, skatt finns där.

5. ✅ Lägg alla  ```Location ```,  ```Player ```,  ```Trap ```,  ```Bandit ``` etc i en world struct som representerar världen.

	**[NOTE TO SELF]**: 
	- ✅ 1st - just merge all structs into one giant struct.
	- 🟡 2nd - later try to create a "meta structure" ...

6. 🟡 [50%] Gör en generell funktion för  ```movePlayer ``` och  ```moveBandit ```. 

	Notera att det är exakt samma värden som sätts. **(spendera max 30 min gör sist)**
	
	(för att göra denna behövs inte nr 5 men det är ett sätt att lösa det på)
