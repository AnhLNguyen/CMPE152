package inter;

import symbols.Type;

public class For extends Stmt {
    Expr expr;
    Stmt stmt;

    public For() {
        expr = null;
        stmt = null;
    }

    public void init(Stmt s, Expr x, Stmt s1, Stmt s2) {
        expr = x;
        if (expr.type != Type.Bool)
            expr.error("boolean required in for");
        children.add(expr);
        stmt = s;
        children.add(stmt);
        stmt = s1;
        children.add(stmt);
        stmt = s2;
        children.add(stmt);
    }

    public String getNodeStr() {
        return "FOR";
    }
}
