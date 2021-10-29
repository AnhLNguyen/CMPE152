package inter;

import symbols.Type;

public class For extends Stmt {

    Expr expr;
    Stmt stmt, stmt1, stmt2;

    public For() {
        // expr = null;
        stmt = null;
        stmt1 = null;
        stmt2 = null;
    }

    public void init(Stmt s, Expr x, Stmt s1, Stmt s2) {
        expr = x;
        stmt = s;
        stmt1 = s1;
        stmt2 = s2;
        if (expr.type != Type.Bool)
            expr.error("boolean required in for");
        children.add(stmt);
        children.add(expr);
        children.add(stmt1);
        children.add(stmt2);
    }

    public String getNodeStr() {
        return "FOR";
    }
}
