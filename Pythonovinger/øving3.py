# -*- coding: ISO8859-10 -*-
#gjort uten Jupyter på grunn av at jeg ikke fikk tilgang til øving 3 på jupyter

def tekstbasertspill(): #jeg lagde et tekstbasert spill i øving to så jeg baserer meg på den
    print("Øving - tekstbasert spill 2")
    game = True
    låstDør = True
    irritasjon = 0
    while(game):
        print("\ndu står utenfor en dør")
        kommando = input(">")
        kommando = kommando.lower() 
        if((kommando == "gå inn" or kommando == "gå inn døren") and låstDør == True):
            print("Døren er låst")
        elif((kommando == "bank på" or kommando == "bank på døren" or kommando == "banker på")and irritasjon >= 5):
            print("Noen sparker opp døren, som treffer deg så hardt at det er dubiøst om du noensinne vil våkne igjen")
            game = False
        elif((kommando == "bank på" or kommando == "bank på døren" or kommando == "banker på")and irritasjon < 5):
            print("Ingen svarer")
            irritasjon += 1
        elif((kommando == "lås opp" or kommando == "lås opp døren")and låstDør == True):
            låstDør = False
            print("Du låser opp døren")
        elif((kommando == "lås opp" or kommando == "lås opp døren")and låstDør == False):
            låstDør = True
            print("Du var tydeligvis ikke fornøyd med å ha låt opp døren en gang, så du låser den igjen")
        elif((kommando == "gå inn" or kommando == "gå inn døren") and låstDør == False):
            game = False
            print("Du går inn og blir med engang skutt av en halvgal redneck")
        elif(kommando == ""):
            game = False
            print("Så dette spillet er ikke bra nok for deg, eller hva?")
        else:
            print("Dette er ikke en støttet kommando")
    print("Du er død og spillet er over")


def intronøstedeløkker():
    print("Øving - intro nøstede løkker")
    deloppgave = input("a,b eller c? ")
    def intronøsteda():
        antStud = int(input("antall studenter: "))
        antEmne = int(input("antall emner: "))
        for x in range(antStud):
            for y in range(antEmne):
                print("Stud", x + 1, "elsker Emne", str(y + 1),";", end=" ")
            print()

    def intronøstedb():
        for time in range(0,24):
            for minutt in range(0,60):
                print(str(time) + ":" + str(minutt), end=" ")
            print()

    def intronøstedc():
        for x in range(1,11):
            for y in range(1,11):
                print(x*y, end="\t")
            print()

    if(deloppgave == 'a'):
        intronøsteda()
    elif(deloppgave == 'b'):
        intronøstedb()
    elif(deloppgave == 'c'):
        intronøstedc()
    else:
        print("Du skrev en ugyldig deloppgave!")


def oppsamlingløkker():
    print("Øving - Mer om løkker oppsamlingsløkker")
    deloppgave = input("a,b eller c? ")
    def oppsamlingløkkera():    
        liste = []
        for i in range(0,7):
            liste.append(int(input("Skriv inn ett tall: ")))
        sum = 0
        for num in liste:
            sum += num
        print(sum)

    def oppsamlingløkkerb():
        produkt = 1
        faktor = 0
        while(produkt <= 1000):
            faktor += 1
            produkt *= faktor
        print(produkt)
    
    def oppsamlingløkkerc():
        rettsvar = "1804"
        antforsøk = 0
        while input("Hvilket år ble Napoleon først kronet til keiser? ") != rettsvar:
            antforsøk += 1
            print("feil, prøv på nytt")
        antforsøk += 1
        print("Rett svar! Du brukte", antforsøk,"forsøk!")

    if(deloppgave == 'a'):
        oppsamlingløkkera()
    elif(deloppgave == 'b'):
        oppsamlingløkkerb()
    elif(deloppgave == 'c'):
        oppsamlingløkkerc()
    else:
        print("Du skrev en ugyldig deloppgave!")

def kodeforståelse():
    print("Øving - Kodeforståelse")
    print("a) 101011001")
    print("b) 0: dette tallet går opp i 4-gangern \n 2\n 4:dette tallet går opp i 4-gangern \n 6 \n 8:dette tallet går opp i 4-gangern")
    print("c) 16")
    print("d) 8")
    print("e) *\n**\n***\n ****\n*****")


gjennomgår = True
while gjennomgår:
    øving = input("Skriv inn øvingoppgave 1-4: ")
    if øving == '0':
        gjennomgår = False
    elif(øving == '1'):
        tekstbasertspill()
    elif(øving == '2'):
        intronøstedeløkker()
    elif(øving == '3'):
        oppsamlingløkker()
    elif(øving == '4'):
        pass
    else:
        print("Du skrev en ugyldig verdi, prøv på nytt")