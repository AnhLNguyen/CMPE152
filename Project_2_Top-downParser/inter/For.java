package inter;

import symbols.Type;

public class For extends Stmt {
    Expr expr;
    Stmt stmt, stmt1, stmt2;

    public For() {
        stmt = null;
        expr = null;
        stmt1 = null;
        stmt2 = null;
    }

    public void init(Stmt s, Expr x, Stmt s1, Stmt s2) {
        expr = x;
        if (expr.type != Type.Bool)
            expr.error("boolean required in for");
        stmt = s;
        children.add(stmt);
        children.add(expr);
        stmt1 = s1;
        children.add(stmt1);
        stmt2 = s2;
        children.add(stmt2);
    }

    public String getNodeStr() {
        return "FOR";
    }
}
