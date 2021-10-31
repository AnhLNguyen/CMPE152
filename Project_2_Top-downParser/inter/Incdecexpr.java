package inter;

import lexer.*;

public class Incdecexpr extends Op {

    public Incdecexpr(Token tok) {
        super(tok, null);
    }

    public String getNodeStr() {
        return "Token " + op.toString();
    }
}
