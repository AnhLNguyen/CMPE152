package inter;

import symbols.*;

public class Incdec extends Stmt {

    public Id id;
    public Expr expr;

    public Incdec(Id i, Expr x1, Expr x2) {
        id = i;
        expr = x1;
        if (check(id.type) == null)
            error("type error");
        children.add(id);
        children.add(expr);
        expr = x2;
        children.add(expr);
    }

    public String getNodeStr() {
        return "INCDECEXPR";
    }

    public Type check(Type p1) {
        if (Type.numeric(p1))
            return p1;
        else
            return null;
    }
}
