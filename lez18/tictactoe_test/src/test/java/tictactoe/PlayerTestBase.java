package tictactoe;

public class PlayerTestBase {

    /**
     * @return la mossa effettuata per passare da 'a' a 'b'
     *         oppure -1
     */
    public int move(Board a, Board b) {
        int mark = a.getNextMark();
        int m = -1;
        int differences = 0;
        for (int i = 0; i < Board.SIZE; i++) {
            int ca = a.getCellContent(i);
            int cb = b.getCellContent(i);
            if (ca == Board.CELL_NONE && cb == mark) {
                m = i;
            }
            if (ca != cb) {
                differences++;
            }
        }
        if (differences == 1) {
            return m;
        } else {
            return -1;
        }
    }
    
}
