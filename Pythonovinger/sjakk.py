# -*- coding: utf-8 -*-
import copy
class Board:
    def __init__(self, board = [], kings = []):
        #konstrukt�r, har lagd en variant som ikke har input en som har input slik at jeg kan lage nye instanser av brettet for � se etter sjakk og matt uten � endre det originale brettet
        if board == [] and kings == []:
            self.board = []
            for x in range(8):
                #lager en ny kolonne
                self.board.append([])
                #setter inn alle b�ndene
                for y in range(8):
                    if(y == 1):
                        self.board[x].append(Pawn([x,y],'w',self))
                    elif(y == 6):
                        self.board[x].append(Pawn([x,y],'b',self))
                    else:
                        self.board[x].append(' ')
            #setter inn alle offiserene
            self.board[0][0],self.board[7][0],self.board[7][7],self.board[0][7] = Rook([0,0],'w',self),Rook([7,0],'w',self),Rook([7,7],'b',self),Rook([0,7],'b',self)
            self.board[1][0],self.board[6][0],self.board[6][7],self.board[1][7] = Knight([1,0],'w',self),Knight([6,0],'w',self),Knight([6,7],'b',self),Knight([1,7],'b',self)
            self.board[2][0],self.board[5][0],self.board[5][7],self.board[2][7] = Bishop([2,0],'w',self),Bishop([5,0],'w',self),Bishop([5,7],'b',self),Bishop([2,7],'b',self)
            self.board[3][0],self.board[3][7] = Queen([3,0],'w',self),Queen([3,7],'b',self)
            self.board[4][0],self.board[4][7] = King([4,0],'w',self),King([4,7],'b',self)
            self.kings = [self.board[4][0], self.board[4][7]]
        else:
            #kopierer brett og lagrer kongene
            self.board = board
            self.kings = kings
    def __str__(self):
        #bruker deepcopy slik at jeg kan endre verdiene inni 2d-arrayen uten � endre den originale arrayen
        out = copy.deepcopy(self.board)
        for x in range(8):
            for y in range(8):
                out[x][y] = str(out[x][y])
        return str(out)
    def getPiece(self,x,y):
        #henter ut en brikke
        return self.board[x][y]
    def moveTo(self,tile,to):
        currentking = None
        #finner kongen som har samme farge som brikken som skal bevege seg
        for king in self.kings:
            if king.getColour() == self.getPiece(tile[0],tile[1]).getColour():
                currentking = king
                break
        #sjekker at brikken finnes, og at den har lov til � bevege seg til det gitte feltet
        allowed = self.getPiece(tile[0],tile[1]) != ' ' and self.getPiece(tile[0],tile[1]).moveTo(to)
        if allowed:
            self.board[tile[0]][tile[1]],self.board[to[0]][to[1]] = ' ',self.board[tile[0]][tile[1]]
            return allowed
        return allowed
    def allowedMove(self,tile,to):
        try:
            if isinstance(self,str):
                return False
            currentking = None
            boardcopy = []
            tempboard = Board(boardcopy,self.kings)
            for x in range(8):
                boardcopy.append([])
                for y in range(8):
                    if self.board[x][y] != ' ':
                        boardcopy[x].append(self.board[x][y].__class__([x,y],self.board[x][y].getColour(),tempboard))
                    else:
                        boardcopy[x].append(' ')

            for king in self.kings:
                if king.getColour() == tempboard.getPiece(tile[0],tile[1]).getColour():
                    currentking = tempboard.getPiece(king.getTile()[0],king.getTile()[1])
                    break
            allowed = to in tempboard.getPiece(tile[0],tile[1]).legalExceptchess()
            boardcopy[to[0]][to[1]],boardcopy[tile[0]][tile[1]] = boardcopy[tile[0]][tile[1]],' '
            allowed = allowed and not currentking.inChess(None,None,boardcopy)
            return allowed
        except:
            return False
    def printBoard(self):
        for y in range(7,-1,-1):
            print(y+1,'|', end='')
            for x in range(0,8):
                print(str(self.board[x][y]),end='|')
            print()
        print("\n   1 2 3 4 5 6 7 8")
    def getBoard(self):
        return self.board
class Piece:
    def __init__(self,tile,colour,board):
        self.tile = tile
        self.colour = colour
        self.symbol = ''
        self.board = board
    def getTile(self):
        return self.tile
    def getColour(self):
        return self.colour
    def __str__(self):
        return self.__symbol__
    def legalMoves(self):
        pass
    def moveTo(self,to):
        if to in self.legalMoves():
            self.tile[0],self.tile[1] = to[0],to[1]
            return True
        return False
    def returnTo(self,to):
        self.tile[0],self.tile[1] = to[0],to[1]
    def getSymbol(self):
        return self.__symbol__
    def legalExceptchess(self):
        return []

class Pawn(Piece):
    def __init__(self,tile,colour,board):
        super().__init__(tile,colour,board)
        if self.colour == 'w':
            self.__symbol__ = '♙'
        elif self.colour == 'b':
            self.__symbol__ = '♟'
    def upgrade(self,to):
        if to == 'Q':
            self.__class__ = Queen
        elif to == 'R':
            self.__class__ = Rook
        elif to == 'B':
            self.__class__ = Bishop
        elif to == 'K':
            self.__class__ = Knight
        self.__init__(self.tile,self.colour,self.board)
        return to == 'Q' or to == 'R' or to == 'B' or to == 'K'
    def legalMoves(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if self.getColour() == 'b':
            if y-1 >= 0:
                if self.board.getPiece(x,y-1)== ' ' and self.board.allowedMove([x,y],(x,y-1)):
                    out.append((x,y-1))
                if y == 6 and self.board.getPiece(x,y-2)== ' 'and self.board.allowedMove([x,y],(x,y-2)):
                    out.append((x,y-2))
                if x-1 >= 0  and self.board.getPiece(x-1,y-1) != ' ' and self.board.getPiece(x-1,y-1).getColour() != self.colour and self.board.allowedMove([x,y],(x-1,y-1)):
                    out.append((x-1,y-1))
                if x+1 < 8  and self.board.getPiece(x+1,y-1) != ' ' and self.board.getPiece(x+1,y-1).getColour() != self.colour and self.board.allowedMove([x,y],(x+1,y-1)):
                    out.append((x+1,y-1))
        elif self.getColour() == 'w':
            if y+1 < 8:
                if self.board.getPiece(x,y+1)== ' ' and self.board.allowedMove([x,y],(x,y+1)):
                    out.append((x,y+1))
                if y == 1 and self.board.getPiece(x,y+2)== ' ' and self.board.allowedMove([x,y],(x,y+2)):
                    out.append((x,y+2))
                if x-1 >= 0  and self.board.getPiece(x-1,y+1) != ' ' and self.board.getPiece(x-1,y+1).getColour() != self.colour and self.board.allowedMove([x,y],(x-1,y+1)):
                    out.append((x-1,y+1))
                if x+1 < 8  and self.board.getPiece(x+1,y+1) != ' ' and self.board.getPiece(x+1,y+1).getColour() != self.colour and self.board.allowedMove([x,y],(x+1,y+1)):
                    out.append((x+1,y+1))
            
        return set(out)
    def legalExceptchess(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if self.getColour() == 'b':
            if y-1 >= 0:
                if self.board.getPiece(x,y-1)== ' ':
                    out.append((x,y-1))
                if y == 6 and self.board.getPiece(x,y-2)== ' ':
                    out.append((x,y-2))
                if x-1 >= 0  and self.board.getPiece(x-1,y-1) != ' ' and self.board.getPiece(x-1,y-1).getColour() != self.colour:
                    out.append((x-1,y-1))
                if x+1 < 8  and self.board.getPiece(x+1,y-1) != ' ' and self.board.getPiece(x+1,y-1).getColour() != self.colour:
                    out.append((x+1,y-1))
        elif self.getColour() == 'w':
            if y+1 < 8:
                if self.board.getPiece(x,y+1)== ' ':
                    out.append((x,y+1))
                if y == 1 and self.board.getPiece(x,y+2)== ' ':
                    out.append((x,y+2))
                if x-1 >= 0  and self.board.getPiece(x-1,y+1) != ' ' and self.board.getPiece(x-1,y+1).getColour != self.colour:
                    out.append((x-1,y+1))
                if x+1 < 8  and self.board.getPiece(x+1,y+1) != ' ' and self.board.getPiece(x+1,y+1).getColour != self.colour:
                    out.append((x+1,y+1))
            
        return set(out)
        
class King(Piece):
    def __init__(self,tile,colour,board):
        super().__init__(tile,colour,board)
        if self.colour == 'w':
            self.__symbol__ = '♔'
        elif self.colour == 'b':
            self.__symbol__ = '♚'
    def hasLegalMove(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        moves = [-1,0,1]
        for move in moves:
            if 0<= x+move<8:
                for movey in moves:
                    if 0<= y+movey <8 and (self.board.getPiece(x+move,y+movey) == ' ' or self.board.getPiece(x+move,y+movey).getColour != self.colour) and not self.inChess(x+move,y+movey):
                        return True
        return False
    def legalMoves(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        moves = [-1,0,1]
        for move in moves:
            if 0<= x+move<8:
                for movey in moves:
                    if 0<= y+movey <8 and (self.board.getPiece(x+move,y+movey) == ' ' or self.board.getPiece(x+move,y+movey).getColour != self.colour) and not self.inChess(x+move,y+movey):
                        out.append((x+move,y+movey))
        return set(out)
    def inChess(self,propx = None,propy = None, board = None):
        if propx == None and propy == None and board != None:
            danger = list((tile for x in board for tile in x  if (tile != ' ' and not isinstance(tile,King) and tile.getColour() != self.colour and ((self.getTile()[0],self.getTile()[1]) in tile.legalExceptchess()))))
            return len(danger) != 0
        elif propx == None and propy == None and board == None:
            danger = list((tile for x in self.board.getBoard() for tile in x  if (tile != ' ' and not isinstance(tile,King) and tile.getColour() != self.colour and ((self.getTile()[0],self.getTile()[1]) in tile.legalExceptchess()))))
            return len(danger) != 0
        else:
            boardcopy = []
            for row in self.board.getBoard():
                boardcopy.append(copy.deepcopy(row))
            boardcopy[self.tile[0]-1][self.tile[1]-1] = ' '
            otherking = list(king for king in self.board.kings if king.getColour() != self.colour )
            otherking = otherking[0].getTile()
            danger = list((tile for x in boardcopy for tile in x if (tile != ' ' and tile.getColour() != self.colour and not isinstance(tile,King) and (propx, propy) in tile.legalMoves())))
            if propx - otherking[0]-1 <= 1 and propy - otherking[1]<=1:
                danger.append(0)
            return len(danger) != 0
    def mate(self):
        danger = set((frozenset(tile.legalMoves()) for x in self.board.getBoard() for tile in x if (tile != ' ' and tile.getColour() == self.colour and not isinstance(tile,King))))
        if self.hasLegalMove():
            return False
        return len(danger) == 1


class Queen(Piece):
    def __init__(self,tile,colour,board):
        super().__init__(tile,colour,board)
        if self.colour == 'w':
            self.__symbol__ = '♕'
        elif self.colour == 'b':
            self.__symbol__ = '♛'
    def legalMoves(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x > 0:
            for xo in range(x-1,-1,-1):
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                if not self.board.allowedMove([x,y],(xo,y)):
                    continue
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
            if y > 0:
                for xo,yo in zip(range(x-1,-1,-1),range(y-1,-1,-1)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x-1,-1,-1),range(y+1,8)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        if x < 7:
            for xo in range(x+1,8):
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                if not self.board.allowedMove([x,y],(xo,y)):
                    continue
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
            if y > 0:
                for xo,yo in zip(range(x+1,8),range(y-1,-1,-1)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x+1,8),range(y+1,8)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        if y > 0:
            for yo in range(y-1,-1,-1):
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                if not self.board.allowedMove([x,y],(x,yo)):
                    continue
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        if y < 7:
            for yo in range(y+1,8):
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                if not self.board.allowedMove([x,y],(x,yo)):
                    continue 
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        return set(out)
    def legalExceptchess(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x > 0:
            for xo in range(x-1,-1,-1):
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
            if y > 0:
                for xo,yo in zip(range(x-1,-1,-1),range(y-1,-1,-1)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x-1,-1,-1),range(y+1,8)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        if x < 7:
            for xo in range(x+1,8):
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
            if y > 0:
                for xo,yo in zip(range(x+1,8),range(y-1,-1,-1)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x+1,8),range(y+1,8)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        if y > 0:
            for yo in range(y-1,-1,-1):
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        if y < 7:
            for yo in range(y+1,8):
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        return set(out)
class Bishop(Piece):
    def __init__(self,tile,colour,board):
        super().__init__(tile,colour,board)
        if self.colour == 'w':
            self.__symbol__ = '♗'
        elif self.colour == 'b':
            self.__symbol__ = '♝'
    def legalMoves(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x > 0:
            if y > 0:
                for xo,yo in zip(range(x-1,-1,-1),range(y-1,-1,-1)):
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x-1,-1,-1),range(y+1,8)):
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        if x < 7:
            if y > 0:
                for xo,yo in zip(range(x+1,8),range(y-1,-1,-1)):
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x+1,8),range(y+1,8)):
                    if not self.board.allowedMove([x,y],(xo,yo)):
                        continue
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        return set(out)
    def legalExceptchess(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x > 0:
            if y > 0:
                for xo,yo in zip(range(x-1,-1,-1),range(y-1,-1,-1)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x-1,-1,-1),range(y+1,8)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        if x < 7:
            if y > 0:
                for xo,yo in zip(range(x+1,8),range(y-1,-1,-1)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
            if y < 7:
                for xo,yo in zip(range(x+1,8),range(y+1,8)):
                    if self.board.getPiece(xo,yo) != ' ' and self.board.getPiece(xo,yo).getColour() == self.colour:
                        break
                    elif self.board.getPiece(xo,yo) != ' ':
                        out.append((xo,yo))
                        break
                    out.append((xo,yo))
        return set(out)
class Knight(Piece):
    def __init__(self,tile,colour,board):
        super().__init__(tile,colour,board)
        if self.colour == 'w':
            self.__symbol__ = '♘'
        elif self.colour == 'b':
            self.__symbol__ = '♞'
    def legalMoves(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x+1<=7:
            if y+2 <= 7 and (self.board.getPiece(x+1,y+2) == ' ' or self.board.getPiece(x+1,y+2).getColour() != self.colour) and self.board.allowedMove([x,y],(x+1,y+2)):
                out.append((x+1,y+2))
            if y-2 >= 0 and (self.board.getPiece(x+1,y-2) == ' ' or self.board.getPiece(x+1,y-2).getColour() != self.colour) and self.board.allowedMove([x,y],(x+1,y-2)):
                out.append((x+1,y-2))
            if x+2<=7:
                if y+1 <= 7 and (self.board.getPiece(x+2,y+1) == ' ' or self.board.getPiece(x+2,y+1).getColour() != self.colour) and self.board.allowedMove([x,y],(x+2,y+1)):
                    out.append((x+2,y+1))and self.board.allowedMove([x,y],(x-2,y+1))
                if y-1 >= 0 and (self.board.getPiece(x+2,y-1) == ' ' or self.board.getPiece(x+2,y-1).getColour() != self.colour) and self.board.allowedMove([x,y],(x+2,y-1)):
                    out.append((x+2,y-1))
        if x-1 >= 0:
            if y+2 <= 7 and (self.board.getPiece(x-1,y+2) == ' ' or self.board.getPiece(x-1,y+2).getColour() != self.colour) and self.board.allowedMove([x,y],(x-1,y+2)):
                out.append((x-1,y+2))
            if y-2 >= 0 and (self.board.getPiece(x-1,y-2) == ' ' or self.board.getPiece(x-1,y-2).getColour() != self.colour) and self.board.allowedMove([x,y],(x-1,y-2)):
                out.append((x-1,y-2))
            if x-2>=0:
                if y+1<=7 and (self.board.getPiece(x-2,y+1) == ' ' or self.board.getPiece(x-2,y+1).getColour() != self.colour) and self.board.allowedMove([x,y],(x-2,y+1)):
                    out.append((x-2,y+1))
                if y-1 >= 0 and (self.board.getPiece(x-2,y-1) == ' ' or self.board.getPiece(x-2,y-1).getColour() != self.colour) and self.board.allowedMove([x,y],(x-2,y-1)):
                    out.append((x-2,y-1))
        return set(out)
    def legalExceptchess(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x+1<=7:
            if y+2 <= 7 and (self.board.getPiece(x+1,y+2) == ' ' or self.board.getPiece(x+1,y+2).getColour() != self.colour):
                out.append((x+1,y+2))
            if y-2 >= 0 and (self.board.getPiece(x+1,y-2) == ' ' or self.board.getPiece(x+1,y-2).getColour() != self.colour):
                out.append((x+1,y-2))
            if x+2<=7:
                if y+1 <= 7 and (self.board.getPiece(x+2,y+1) == ' ' or self.board.getPiece(x+2,y+1).getColour() != self.colour):
                    out.append((x+2,y+1))
                if y-1 >= 0 and (self.board.getPiece(x+2,y-1) == ' ' or self.board.getPiece(x+2,y-1).getColour() != self.colour):
                    out.append((x+2,y-1))
        if x-1 >= 0:
            if y+2 <= 7 and (self.board.getPiece(x-1,y+2) == ' ' or self.board.getPiece(x-1,y+2).getColour() != self.colour):
                out.append((x-1,y+2))
            if y-2 >= 0 and (self.board.getPiece(x-1,y-2) == ' ' or self.board.getPiece(x-1,y-2).getColour() != self.colour):
                out.append((x-1,y-2))
            if x-2>=0:
                if y+1<=7 and (self.board.getPiece(x-2,y+1) == ' ' or self.board.getPiece(x-2,y+1).getColour() != self.colour):
                    out.append((x-2,y+1))
                if y-1 >= 0 and (self.board.getPiece(x-2,y-1) == ' ' or self.board.getPiece(x-2,y-1).getColour() != self.colour):
                    out.append((x-2,y-1))
        return set(out)
class Rook(Piece):
    def __init__(self,tile,colour,board):
        super().__init__(tile,colour,board)
        if self.colour == 'w':
            self.__symbol__ = '♖'
        elif self.colour == 'b':
            self.__symbol__ = '♜'
    def legalMoves(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x > 0:
            for xo in range(x-1,-1,-1):
                if not self.board.allowedMove([x,y],(xo,y)):
                    continue
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
        if x < 7:
            for xo in range(x+1,8):
                if not self.board.allowedMove([x,y],(xo,y)):
                    continue
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
        if y > 0:
            for yo in range(y-1,-1,-1):
                if not self.board.allowedMove([x,y],(x,yo)):
                    continue
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        if y < 7:
            for yo in range(y+1,8):
                if not self.board.allowedMove([x,y],(x,yo)):
                    continue
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        return set(out)
    
    def legalExceptchess(self):
        out = []
        x = self.getTile()[0]
        y = self.getTile()[1]
        if x > 0:
            for xo in range(x-1,-1,-1):
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
        if x < 7:
            for xo in range(x+1,8):
                if self.board.getPiece(xo,y) != ' ' and self.board.getPiece(xo,y).getColour() == self.colour:
                    break
                elif self.board.getPiece(xo,y) != ' ':
                    out.append((xo,y))
                    break
                out.append((xo,y))
        if y > 0:
            for yo in range(y-1,-1,-1):
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        if y < 7:
            for yo in range(y+1,8):
                if self.board.getPiece(x,yo) != ' ' and self.board.getPiece(x,yo).getColour() == self.colour:
                    break
                elif self.board.getPiece(x,yo) != ' ':
                    out.append((x,yo))
                    break
                out.append((x,yo))
        return set(out)



def main():
    aboard = Board()
    round = 0
    farger = ['hvit','sort']
    farge = ['w','b']
    while(not aboard.kings[0].mate() and not aboard.kings[1].mate()):
        if aboard.kings[round%2].inChess():
            print("du er i sjakk")
        aboard.printBoard()
        trekk = input(farger[round%2] + " sin tur. Skriv inn ditt trekk (format '(brikkex,brikkey),(tilx,tily)'): ")
        trekk = trekk.replace('(','').replace(')','')
        trekk = trekk.split(',')
        try:
            formaterttrekk = [[int(trekk[0])-1,int(trekk[1]) -1],tuple([int(trekk[2])-1,int(trekk[3])-1])]
            if aboard.getPiece(formaterttrekk[0][0],formaterttrekk[0][1]) != ' ' and aboard.getPiece(formaterttrekk[0][0],formaterttrekk[0][1]).getColour() == farge[round%2] and aboard.moveTo(formaterttrekk[0],formaterttrekk[1]):
                round += 1
                if isinstance(aboard.getPiece(formaterttrekk[1][0],formaterttrekk[1][1]),Pawn) and 7 == formaterttrekk[1][1]:
                    while(True):
                        oppgrader = input("hva vil du oppgradere bonden til (Q,B,K,R)? ")
                        if aboard.getPiece(formaterttrekk[1][0],formaterttrekk[1][1]).upgrade(oppgrader):
                            break
            else:
                print("ulovlig trekk, prøv noe lovlig neste gang")
        except:
            print("ulovlig trekk, prøv noe lovlig neste gang")
    aboard.printBoard()
    print(farger[(round-1)%2], "vant!")

main()

