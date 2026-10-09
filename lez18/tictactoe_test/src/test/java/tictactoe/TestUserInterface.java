/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tictactoe;

/**
 *
 * @author foggia
 */
public class TestUserInterface extends UserInterface {
    private int nextMove;
    private boolean resultShown=false;
    
    public void setNextMove(int m) {
        nextMove=m;
    }
    
    @Override
    public int askMove(Board b) {
        return nextMove;
    }
    
    public boolean isResultShown() {
        return resultShown;
    }
    
    public void clearResultShown() {
        resultShown=false;
    }
    
    @Override
    public void showResult(String message) {
        resultShown=true;
    }
}
