import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.List;
public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.
    private ArrayList<String> methods;
    private Class<?> class_s;
    private Method[] method;

    public ArrayList<String> ghostMethods(){
        methods = new ArrayList<>();
        class_s = Ghost.class;
        method = class_s.getDeclaredMethods();
        for (Method m : method) {
            methods.add(m.getName());
        }
        return methods;
    }   

    public Integer sumGhost() throws Exception{
        int sum = 0;
        class_s = Ghost.class;
        Ghost ghost = new Ghost();
        Method[] methodd = class_s.getDeclaredMethods();
        for (Method m : methodd) {
            if (m.getReturnType() == int.class || m.getReturnType() == Integer.class) {
                m.setAccessible(true);
                sum += (Integer) m.invoke(ghost); // Panggil method dan tambahkan hasilnya
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception{
        StringBuilder sb = new StringBuilder();
        class_s = Ghost.class;
        Ghost ghost = new Ghost();
        Method[] methodd = class_s.getDeclaredMethods();
        for (Method m : methodd) {
            if (m.getReturnType() == String.class) {
                m.setAccessible(true);
                sb.append((String) m.invoke(ghost)); // Panggil method dan ambil hasilnya
            }
        }
        return sb.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        Field sField;
        for (Secret s : sl) if (s.isThis(email)) {
            sField = s.getClass().getDeclaredField("uniqueId");
            sField.setAccessible(true);
            return (String) sField.get(s);
        }
        return "NaN";
    }
}
