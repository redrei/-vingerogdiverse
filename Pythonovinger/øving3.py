# -*- coding: ISO8859-10 -*-
#gjort uten Jupyter p� grunn av at jeg ikke fikk tilgang til �ving 3 p� jupyter

def tekstbasertspill(): #jeg lagde et tekstbasert spill i �ving to s� jeg baserer meg p� den
    print("�ving - tekstbasert spill 2")
    game = True
    l�stD�r = True
    irritasjon = 0
    while(game):
        print("\ndu st�r utenfor en d�r")
        kommando = input(">")
        kommando = kommando.lower() 
        if((kommando == "g� inn" or kommando == "g� inn d�ren") and l�stD�r == True):
            print("D�ren er l�st")
        elif((kommando == "bank p�" or kommando == "bank p� d�ren" or kommando == "banker p�")and irritasjon >= 5):
            print("Noen sparker opp d�ren, som treffer deg s� hardt at det er dubi�st om du noensinne vil v�kne igjen")
            game = False
        elif((kommando == "bank p�" or kommando == "bank p� d�ren" or kommando == "banker p�")and irritasjon < 5):
            print("Ingen svarer")
            irritasjon += 1
        elif((kommando == "l�s opp" or kommando == "l�s opp d�ren")and l�stD�r == True):
            l�stD�r = False
            print("Du l�ser opp d�ren")
        elif((kommando == "l�s opp" or kommando == "l�s opp d�ren")and l�stD�r == False):
            l�stD�r = True
            print("Du var tydeligvis ikke forn�yd med � ha l�t opp d�ren en gang, s� du l�ser den igjen")
        elif((kommando == "g� inn" or kommando == "g� inn d�ren") and l�stD�r == False):
            game = False
            print("Du g�r inn og blir med engang skutt av en halvgal redneck")
        elif(kommando == ""):
            game = False
            print("S� dette spillet er ikke bra nok for deg, eller hva?")
        else:
            print("Dette er ikke en st�ttet kommando")
    print("Du er d�d og spillet er over")


def intron�stedel�kker():
    print("�ving - intro n�stede l�kker")
    deloppgave = input("a,b eller c? ")
    def intron�steda():
        antStud = int(input("antall studenter: "))
        antEmne = int(input("antall emner: "))
        for x in range(antStud):
            for y in range(antEmne):
                print("Stud", x + 1, "elsker Emne", str(y + 1),";", end=" ")
            print()

    def intron�stedb():
        for time in range(0,24):
            for minutt in range(0,60):
                print(str(time) + ":" + str(minutt), end=" ")
            print()

    def intron�stedc():
        for x in range(1,11):
            for y in range(1,11):
                print(x*y, end="\t")
            print()

    if(deloppgave == 'a'):
        intron�steda()
    elif(deloppgave == 'b'):
        intron�stedb()
    elif(deloppgave == 'c'):
        intron�stedc()
    else:
        print("Du skrev en ugyldig deloppgave!")


def oppsamlingl�kker():
    print("�ving - Mer om l�kker oppsamlingsl�kker")
    deloppgave = input("a,b eller c? ")
    def oppsamlingl�kkera():    
        liste = []
        for i in range(0,7):
            liste.append(int(input("Skriv inn ett tall: ")))
        sum = 0
        for num in liste:
            sum += num
        print(sum)

    def oppsamlingl�kkerb():
        produkt = 1
        faktor = 0
        while(produkt <= 1000):
            faktor += 1
            produkt *= faktor
        print(produkt)
    
    def oppsamlingl�kkerc():
        rettsvar = "1804"
        antfors�k = 0
        while input("Hvilket �r ble Napoleon f�rst kronet til keiser? ") != rettsvar:
            antfors�k += 1
            print("feil, pr�v p� nytt")
        antfors�k += 1
        print("Rett svar! Du brukte", antfors�k,"fors�k!")

    if(deloppgave == 'a'):
        oppsamlingl�kkera()
    elif(deloppgave == 'b'):
        oppsamlingl�kkerb()
    elif(deloppgave == 'c'):
        oppsamlingl�kkerc()
    else:
        print("Du skrev en ugyldig deloppgave!")

def kodeforst�else():
    print("�ving - Kodeforst�else")
    print("a) 101011001")
    print("b) 0: dette tallet g�r opp i 4-gangern \n 2\n 4:dette tallet g�r opp i 4-gangern \n 6 \n 8:dette tallet g�r opp i 4-gangern")
    print("c) 16")
    print("d) 8")
    print("e) *\n**\n***\n ****\n*****")


gjennomg�r = True
while gjennomg�r:
    �ving = input("Skriv inn �vingoppgave 1-4: ")
    if �ving == '0':
        gjennomg�r = False
    elif(�ving == '1'):
        tekstbasertspill()
    elif(�ving == '2'):
        intron�stedel�kker()
    elif(�ving == '3'):
        oppsamlingl�kker()
    elif(�ving == '4'):
        pass
    else:
        print("Du skrev en ugyldig verdi, pr�v p� nytt")