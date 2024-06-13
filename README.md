תיעוד קוד גרף C++

ID: 207723198
Mail: yair852258@gmail.com

תיאור הפרויקט:
הפרויקט מיישם מספר אלגוריתמים נפוצים על גרפים, המיוצגים באמצעות מטריצת שכנויות. הוא מורכב משתי מחלקות עיקריות:

 Graph:

    loadGraph(const vector<vector<int>>& adjacencyMatrix)
    טוענת גרף ממטריצת שכנויות. מקבלת מטריצת שכנויות כפרמטר ובודקת את תקינותה (גודל, ערכים). מעדכנת את מטריצת השכנויות של מחלקת הגרף.

    printGraph() const
    מדפיסה את ייצוג הגרף, כולל מטריצת השכנויות, מספר הקודקודים ומספר הצלעות.

    countEdges() const
    סופרת את מספר הצלעות במטריצת השכנויות, תוך התחשבות אם הגרף מכוון או לא.

    isDirected() const
    בודקת אם הגרף מכוון על ידי השוואת הערכים במטריצת השכנויות. מחזירה true אם הגרף מכוון, אחרת מחזירה false.

    getGraph() const    
    מחזירה עותק של מטריצת השכנויות של הגרף

    isWeighted() const
    בודקת אם הגרף ממושקל על ידי מעבר על מטריצת השכנויות ובדיקת ערכים שאינם 0 או 1. מחזירה 1 אם הגרף ממושקל, 0 אם לא ממושקל, ו- -1 אם יש משקל שלילי.

    

 Algorithms:

    isConnected(const Graph &graph)
    בודקת אם הגרף קשיר באמצעות חיפוש עומק (DFS). אם הגרף מכוון, מבצעת DFS פעמיים - פעם אחת מאחד הקודקודים הראשיים ופעם נוספת מקודקוד אחר.

    shortestPath(const Graph &graph, int start, int end)
    מוצאת את המסלול הקצר ביותר בין שני קודקודים בגרף. משתמשת ב-BFS עבור גרפים לא ממושקלים, ב-Bellman-Ford עבור גרפים עם צלעות שליליות, וב-Dijkstra עבור גרפים עם צלעות חיוביות.

    isContainsCycle(const Graph &graph)
    בודקת אם יש מעגלים בגרף באמצעות DFS מכל קודקוד שלא נבדק.

    isBipartite(const Graph &graph)
    בודקת אם הגרף דו-חלוקתי באמצעות BFS לצביעת הקודקודים בשני צבעים שונים כך שקודקודים סמוכים יצבעו בצבעים שונים.

    negativeCycle(const Graph &graph)
    בודקת אם יש מעגלים שליליים בגרף באמצעות אלגוריתם Bellman-Ford. מחזירה true אם נמצא מעגל שלילי, אחרת false.

פונקציות עזר (מוגדרות פרטיות ומשמשות רק בתוך המחלקה):

    dfs(const Graph &graph, vector<bool> &visited, size_t current_node)
    מבצעת סיור עומק (DFS) בגרף, מעדכנת את הקודקודים שכבר ביקרה בהם במערך (visited).

    dfsCycleHelper(const vector<vector<int>> &adjMatrix, size_t node, int parentNode, vector<bool> &visited, vector<bool> &detectBackEdges, vector<size_t> &cyclePath)
    מבצעת DFS בגרף לאיתור מעגלים, משתמשת ברשומת קריאה של BackEdges אחר הביקור בקודקודים כדי לזהות מעגלים. כאשר מוצאת מעגל, מוסיפה את הקודקודים במעגל למערך cyclePath.

    formatCyclePath(const vector<size_t> &pathCycle)
    בונה מחרוזת המייצגת את המעגל שנמצא בגרף.

    bfs(const Graph &graph, size_t start, size_t end);
    מחפשת מסלול קצר ביותר בין שני צמתים באמצעות סיור BFS.

    Dijkstra(const Graph &graph, size_t start, size_t end)
    מחשבת את המסלול הקצר ביותר בין שני צמתים באמצעות אלגוריתם דייקסטרה.

    BellmanFord(const Graph &graph, size_t start, size_t end)
    מוצאת את המסלול הקצר ביותר בין שני צמתים, כולל צמתים עם משקלים שליליים, באמצעות אלגוריתם בלמן-פורד.

קבצי בדיקה:

    Demo
    מכיל פונקצית main דוגמאות של קלטים ופלטים של הפונקציות.

    Test
    מכיל מספר טסטים לכל פונקציה ציבורית.

קומפיילר:
g++

הפעלה:

    make run - Demoלהרצת קובץ ה
    make runtest - להרצת קובץ הטסט