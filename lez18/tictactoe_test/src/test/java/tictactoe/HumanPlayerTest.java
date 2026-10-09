/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tictactoe;
import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;
/**
 *
 * @author foggia
 */
public class HumanPlayerTest extends PlayerTestBase {
    @Test
    public void testConstructor() {
        TestUserInterface tui=new TestUserInterface();
        HumanPlayer hp1=new HumanPlayer(Board.CELL_X, tui);
        assertEquals(Board.CELL_X, hp1.getMark());
        
        HumanPlayer hp2=new HumanPlayer(Board.CELL_O, tui);
        assertEquals(Board.CELL_O, hp2.getMark());        
    }
    
    @Test
    public void testMakeMove() {
        Board b=new Board();
        b.applyMove(0);
        b.applyMove(4);
        Board copy=new Board(b);
        
        TestUserInterface tui=new TestUserInterface();
        tui.setNextMove(2);
        
        HumanPlayer hp=new HumanPlayer(Board.CELL_X, tui);
        hp.makeMove(b);
        
        int m=move(copy, b);
        assertEquals(2, m);
    }
    
    @Test
    public void testNotifyResult() {
        TestUserInterface tui=new TestUserInterface();
        HumanPlayer hp=new HumanPlayer(Board.CELL_X, tui);
        assertFalse(tui.isResultShown());
        hp.notifyResult(Board.CELL_X);
        assertTrue(tui.isResultShown());
    }
}
