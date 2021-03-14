import org.w3c.dom.Node;
import org.w3c.dom.Element;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.io.*;
import java.util.ListIterator;

public class XMLSample
{
    private final String INPUT = "students.xml";
    private  final  String  OUTPUT = "students.xml";
    private ArrayList<Student> students;

    private String getValue(NodeList fields, int index)
    {
        NodeList list = fields.item(index).getChildNodes();
        if (list.getLength() > 0) {
            return list.item(0).getNodeValue();
        } else {
            return "";
        }
    }
    public ArrayList readDataXML() {
        students = new ArrayList<Student>();

        SimpleDateFormat sdf = null;
        DocumentBuilderFactory dbf = null;
        DocumentBuilder db = null;
        Document doc = null;
        try {

            dbf = DocumentBuilderFactory.newInstance();
            db = dbf.newDocumentBuilder();
            doc = null;

            FileInputStream fis = null;
            try {
                fis = new FileInputStream(INPUT);
                doc = db.parse(fis);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

            doc.getDocumentElement().normalize();

            NodeList fields = null;
            NodeList nodeList = null;

            nodeList = doc.getElementsByTagName("Student");
            for (int s = 0; s < nodeList.getLength(); s++) {
                Node node = nodeList.item(s);
                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Student student = new Student();
                    Element el = (Element) node;
                    fields = el.getElementsByTagName("field");
                    student.setNumber(getValue(fields, 0));
                    student.setName((getValue(fields, 1)));
                    student.setSubject(getValue(fields, 2));
                    student.setMark(getValue(fields, 3));
                    students.add(student);
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
       return students;
    }
    public void writeDataXML(ArrayList<Student> students)
    {
        DocumentBuilderFactory dbf = null;
        DocumentBuilder        db  = null;
        Document               doc = null;
        try {
            dbf = DocumentBuilderFactory.newInstance();
            db  = dbf.newDocumentBuilder();
            doc = db.newDocument();

            Element e_root = doc.createElement("Root");
            e_root.setAttribute("lang", "en");
            doc.appendChild(e_root);
            if (students.size() == 0)
                return;
            ListIterator<Student> iterator =students.listIterator();
            while(iterator.hasNext()){
                Element e_users  = doc.createElement("Student");
                e_root.appendChild(e_users);
                ArrayList<String> arrayList = new ArrayList<String>();
                Student temp=new Student();
                temp=iterator.next();
                arrayList.add(temp.getNumber());
                arrayList.add(temp.getName());
                arrayList.add(temp.getSubject());
                arrayList.add(temp.getMark());
                ListIterator<String> iterator1=arrayList.listIterator();
                while (iterator1.hasNext()) {
                    Element e = doc.createElement("field");
                    e.setTextContent(iterator1.next());
                    e_users.appendChild (e);
                }
            }

        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        } finally {
            // Сохраняем Document в XML-файл
            if (doc != null)
                writeDocument(doc, OUTPUT);
        }
    }
    public void writeDocument(Document document, String path)
            throws TransformerFactoryConfigurationError
    {
        Transformer trf = null;
        DOMSource src = null;
        FileOutputStream fos = null;
        try {
            trf = TransformerFactory.newInstance().newTransformer();
            src = new DOMSource(document);
            fos = new FileOutputStream(path);

            StreamResult result = new StreamResult(fos);
            trf.setOutputProperty(OutputKeys.INDENT,"yes");
            trf.transform(src, result);
        } catch (TransformerException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}