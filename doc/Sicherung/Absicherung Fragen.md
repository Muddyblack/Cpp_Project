FAQ:

F1: Sollen wir, wenn mehrere Inputdateien angegeben sind und in einer davon ein "sort" angegeben ist, die gesamte Outputdatei sortieren oder soll die gesamte Outputdatei nur bei "getopt" sortiert werden?

A1: Wenn mehrere Inputdateien vorliegen und nur bei einer "sort" verlangt wird, dann werden auch nur die Inhalte dieser Datei in deren Outputdatei sortiert. Pro Inputdatei kann ja eine andere Outputdatei gegeben sein. Wenn die Kommandozeile Überrang hat und eine gemeinsame Outputdatei vorgibt, dann gilt auch das von der Kommandozeile vorgegebene sort=true/false.

F2: Sollen mehrere Outputdateien generiert werden können und falls ja wie interagieren einzelne Inputdatei miteinander (mit @start und @end)? Könnten Sie uns dazu vielleicht ein Beispiel nennen, da das momentan unser Hauptproblem darstellt?

A2: Jede Inputdatei kann ihre eigene Outputdatei haben. Verarbeiten Sie die Inputdateien eine nach der anderen.

F3: Wie stellen Sie sich die "addElement" Methode vor und was ist hier mit Verkettung gemeint (Einfachverkettetes Array)?

A3: Die AddElement Methode ist ein Wink mit dem Zaunpfahl dass hier eine Liste gewünscht ist.

F4: Die Repräsentation der Variablen aus den Inputdateien soll ja mittels verketteter Listen erfolgen. Die Implementierung soll durch die Basisklasse CTextToCpp und deren abgeleiteten Klassen für die einzelnen Variablentypen erfolgen. Sollen Instanzen dieser Klassen als die eigentlichen Elemente der verketteten Liste gesehen werden oder dienen diese als "Container" für die verkettete Liste (d.h. der Zeiger auf das erste Element ist in den Instanzen der Klassen als Attribut gespeichert)?

A4: Die Klasse CTextToCPP ist als die Basisklasse gedacht, über deren Pointer man auf die einzelnen Elemente der Liste zugreifen kann, egal welcher Subklasse dieses Element entstammt. Dh, die Instanzen der Subklassen sind die Listenelemente verbunden über den Pointer „CTextToCPP \* next;“ Die Basisklasse ist nicht zur Instanziierung gedacht, da sie ja abstrakt ist. Allerdings können die einzelnen Methoden zur Verwaltung der Inputdatei ja trotzdem hier ausimplementiert sein und durch static auch aus Ihrer main-Funktion benutzt werden. Dh in Ihrer main lesen sie die Datei ein und erstellen und verwalten die Liste aus Elementen der Subklassen, je nachdem welche EscapeSequenzen die Input-Datei fordert. Anschließend können sie einfach die Liste iterieren und jedes Element zur Ausgabe auffordern, die ja dann passend zur jeweiligen Escape-Sequenz sein sollte.

F5: Wenn per CLI z.B. mehrere Inputdateien eingegeben werden und ebenso der Name der Outputfile, sollen dann die Inputdateien in eine Outputfile gewandelt werden?

A5: Nein, eine Inputdatei erzeugt jeweils eine Header-/Sourcedatei und wenn mehrere Inputdateidateien mit einem Outputfilename verknüpft sind, sei es durch Namesgleichheit in der Inputdatei oder durch die Angabe nur einer Outputdatei bei Angabe mehrerer Inputdateien, dann erzeugt das Programm mit jedem Durchgang einer Inputdatei ein Outputdateipaar das dann den gleichen Namen hat und sich überschreibt.

F6: Und sollen mehrere Outputdateien per CLI angegeben werden können und wenn ja, wie verhält sich das dann mit den Inputdateien in diesem Zusammenhang?

A6: Nein

F7: Wenn z.B. drei Inputdateien und kein Outputfile per CLI angegeben sind, sollen dann auch drei Outputfiles erstellt werden (ggf. jeweils mit Source und Headerdatei)?

A7: Kommt darauf an welche Outputfilesnames in den Inputdateien definiert sind. Bei Namensgleichheit überschreiben sie sich, bei unterschiedliche Namen werden sie erzeugt und sollte in keinem einen Namen angegeben werden die Namen aus dem Namen der Inputdatei erzeugt

F8: Wenn z.B. drei Inputdateien und keine Outputfile per CLI angegeben sind und zusätzlich in den Inputdateien keine @tags mit "outputfilename" vorhanden sind, soll dann eine einzige "default_output"-Datei erstellt werden oder wie soll hier verfahren werden?

A8: Bei einer Inputdatei (oder multiple) die keine Steuerinformation enthält, wird der Namen aus dem Namen der Inputdatei erzeugt (Reqfunc13 /14)

F9: Wenn keine @tags in den Inputdateien vorhanden sind und auch keine übergeben werden per CLI, was für Standardparameter sollen verwendet werden oder soll das Programm einen Abbruchfehler werfen?

A9: Siehe Reqfunc13/14

F10: Wenn ein Outputfile angegeben wurde und ein Argument (z.B. signperline) per CLI nicht übergeben wurde aber zwei Inputfiles vorhanden sind in denen zwei verschiedene Parameter für dieses Argument angegeben wurden, welcher Parameter soll verwendet werden?

A10: Jede Inputdatei erzeugt ihren eigenen Output, d.h. demzufolge jeder Parameter ist einer Datei oder Abschnitt zuordbar

F11: Ich möchte gerne eine Frage zum "nl"-Parameter in Bezug auf die Verwendung in Variablen stellen Mir ist aufgefallen, dass dies zu potenziellen Problemen führen könnte, insbesondere wenn eine Eingabedatei mit z.B. den drei verschiedenen Zuständen verwendet wird, von denen jeder für einen unterschiedlichen "\n"-Zeichen steht. Dies würde dazu führen, dass in z.B. einer Ausgabedatei drei verschiedene Betriebssysteme angesprochen werden. Darüber hinaus habe ich bemerkt, dass bei Verwendung von CR (Mac) als "/n" unter Windows die Gefahr besteht, dass die Zeile überschrieben wird. Dies ist ja auch logisch, da wir hier nur den Courser zurück zum Zeilenanfang schieben. Daher möchte ich Sie bitten, zu überprüfen, ob der "nl"-Parameter in dieser Variablenstruktur wirklich sinnvoll ist. Oder dieser eigentlich in den @globla Tag gehört? Und wenn ja, sollen wir das noch anpassen oder wird das nicht bewertet.

A11: Die Idee ist das wir aus einer Textdatei Texte für zwei anderen System zu erzeugen, Terminalansteuerung über serielle Schnittstelle (RS232) ->CRLF, LCD Anzeige ->LF

F12: Sollen Zeilenumbrüche in der eingelesenen Textdatei auch in der generierten .c- oder .cpp Datei Zeilenumbrüche bewirken? Also so, dass in der generierten Outputdatei eine Zeile der Variablen immer die in "signperline" vorgegebene Anzahl an Zeichen enthält, außer bei Zeilen, in denen im Original ein Zeilenumbruch war. Diese Zeilen wären dann entsprechend der Position des Zeilenumbruchs kürzer.

A12: Ja, vorhandene Zeilenumbrüche sollen erhalten bleiben.
