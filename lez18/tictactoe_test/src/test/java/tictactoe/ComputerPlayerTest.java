package tictactoe;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

public class ComputerPlayerTest extends PlayerTestBase {
    
    @Test
    public void testConstructor() {
        ComputerPlayer p1=new ComputerPlayer(Board.CELL_X, 2);
        assertEquals(Board.CELL_X, p1.getMark());
        
        ComputerPlayer p2=new ComputerPlayer(Board.CELL_O, 2);
        assertEquals(Board.CELL_O, p2.getMark());
    }
    
    @Test
    public void testMakeMove1() {
        Board b=new Board();
        b.applyMove(0);
        b.applyMove(4);
        ComputerPlayer cp=new ComputerPlayer(Board.CELL_X, 0);
        Board copy=new Board(b);
        cp.makeMove(b);
        int m=move(copy, b);
        assertTrue(m==1 || m==2 || m==3
                  || m==5 || m==6 || m==7 || m==8);
    }
    
    
    @Test
    public void testMakeMove2() {
        Board b=new Board();
        b.applyMove(0);
        b.applyMove(2);
        b.applyMove(6);
        b.applyMove(4);
        ComputerPlayer cp=new ComputerPlayer(Board.CELL_X, 1);
        Board copy=new Board(b);
        cp.makeMove(b);
        int m=move(copy, b);
        assertEquals(3, m);
    }
    
    @Test
    public void testMakeMove3() {
        Board b=new Board();
        b.applyMove(0);
        b.applyMove(2);
        b.applyMove(1);
        b.applyMove(7);
        b.applyMove(3);
        ComputerPlayer cp=new ComputerPlayer(Board.CELL_O, 2);
        Board copy=new Board(b);
        cp.makeMove(b);
        int m=move(copy, b);
        assertEquals(6, m);
    }
    
    @Test
    public void testMakeMove4() {
        Board b=new Board();
        b.applyMove(4);
        b.applyMove(2);
        b.applyMove(6);
        b.applyMove(7);
        ComputerPlayer cp=new ComputerPlayer(Board.CELL_X, 3);
        Board copy=new Board(b);
        cp.makeMove(b);
        int m=move(copy, b);
        assertTrue(m==0 || m==3);
    }
    
}
