package tictactoe;
import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;


public class BoardTest {
    private Board board;
    
    @BeforeEach
    public void setUp() {
        board=new Board();
    }
    
    @Test
    public void testConstructor() {
        for(int i=0; i<Board.SIZE; i++)
            assertEquals(Board.CELL_NONE,
                    board.getCellContent(i));
        assertEquals(Board.CELL_X, board.getNextMark());
    }
    
    @Test
    public void testCopyConstructor() {
        board.applyMove(0);
        board.applyMove(1);
        board.applyMove(4);
        Board copy=new Board(board);
        for(int i=0; i<Board.SIZE; i++)
            assertEquals(board.getCellContent(i),
                         copy.getCellContent(i));
        assertEquals(board.getNextMark(), 
                copy.getNextMark());
    }

    @Test
    public void testGetNextMark() {
        board.applyMove(0);
        board.applyMove(1);
        board.applyMove(4);
        
        assertEquals(Board.CELL_O, 
                board.getNextMark());
        
        board.applyMove(8);
        assertEquals(Board.CELL_X, 
                board.getNextMark());        
    }
    
    @Test
    public void testGetCellContent() {
        board.applyMove(0);
        board.applyMove(1);
        board.applyMove(4);
        
        assertEquals(Board.CELL_X, 
                board.getCellContent(0));
        assertEquals(Board.CELL_O, 
                board.getCellContent(1));
        assertEquals(Board.CELL_NONE, 
                board.getCellContent(2));
        assertEquals(Board.CELL_NONE, 
                board.getCellContent(3));
        assertEquals(Board.CELL_X, 
                board.getCellContent(4));
        for(int i=5; i<Board.SIZE; i++)
            assertEquals(Board.CELL_NONE, 
                board.getCellContent(i));
    }
    
    @Test
    public void testIsValidMove() {
        board.applyMove(0);
        board.applyMove(4);
        assertTrue(board.isValidMove(2));
        assertFalse(board.isValidMove(4));
    }
    
    @Test
    public void testIsEnded1() {
        board.applyMove(0);
        board.applyMove(4);
        assertFalse(board.isEnded());
    }
    
    @Test
    public void testIsEnded2() {
        board.applyMove(0);
        board.applyMove(1);
        board.applyMove(2);
        board.applyMove(4);
        board.applyMove(3);
        board.applyMove(6);
        board.applyMove(5);
        board.applyMove(8);
        board.applyMove(7);
        assertTrue(board.isEnded());
        assertEquals(Board.CELL_NONE, 
                board.getWinner());
    }
    
    @Test
    public void testIsEnded3() {
        board.applyMove(2);
        board.applyMove(0);
        board.applyMove(6);
        board.applyMove(8);
        board.applyMove(4);

        assertTrue(board.isEnded());
        assertEquals(Board.CELL_X, 
                board.getWinner());
    }

    @Test
    public void testIsEnded4() {
        Board board = new Board ();
        board.applyMove(2);
        board.applyMove(0);
        board.applyMove(7);
        board.applyMove(6);
        board.applyMove(1);
        board.applyMove(3);

        assertTrue(board.isEnded());
        assertEquals(Board.CELL_O, 
                board.getWinner());
    }

    @Test
    public void testGetOpponentMark() {
        assertEquals(Board.CELL_O,
                Board.getOpponentMark(Board.CELL_X));
        assertEquals(Board.CELL_X,
                Board.getOpponentMark(Board.CELL_O));
        
    }
}
