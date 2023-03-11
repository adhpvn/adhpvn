import java.util.*;

class Citizen {
    String code, dateOfBirth, fatherCode, motherCode, isAlive, regionCode;

    public Citizen(String code, String dateOfBirth, String fatherCode, String motherCode, String isAlive,
            String regionCode) {
        this.code = code;
        this.dateOfBirth = dateOfBirth;
        this.fatherCode = fatherCode;
        this.motherCode = motherCode;
        this.isAlive = isAlive;
        this.regionCode = regionCode;
    }
}

public class CitizenDatabase {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Map<String, Citizen> citizenMap = new HashMap<>();
    int numOfCitizens = 0;

    while (sc.hasNextLine()) {
        String line = sc.nextLine();
        if (line.equals("*")) {
            break;
        }
        String[] data = line.split(" ");
        Citizen citizen = new Citizen(data[0], data[1], data[2], data[3], data[4], data[5]);
        citizenMap.put(data[0], citizen);
        numOfCitizens++;
    }

    while (sc.hasNextLine()) {
        String line = sc.nextLine();
        if (line.equals("***")) {
            break;
        }

        String[] query = line.split(" ");
        switch (query[0]) {
            case "NUMBER_PEOPLE":
                System.out.println(numOfCitizens);
                break;

            case "NUMBER_PEOPLE_BORN_AT":
                int count1 = 0;
                for (Citizen citizen : citizenMap.values()) {
                    if (citizen.dateOfBirth.equals(query[1])) {
                        count1++;
                    }
                }
                System.out.println(count1);
                break;

            case "MOST_ALIVE_ANCESTOR":
                int generation = 0;
                String code = query[1];
                while (!code.equals("0000000")) {
                    Citizen ancestor = citizenMap.get(code);
                    if (ancestor == null) {
                        System.out.println("Invalid code: " + code);
                        break;
                    }
                    if (ancestor.isAlive.equals("Y")) {
                        System.out.println(generation);
                        break;
                    }
                    code = ancestor.fatherCode;
                    generation++;
                }
                break;

            case "NUMBER_PEOPLE_BORN_BETWEEN":
                int count2 = 0;
                for (Citizen citizen : citizenMap.values()) {
                    if (citizen.dateOfBirth.compareTo(query[1]) >= 0 && citizen.dateOfBirth.compareTo(query[2]) <= 0) {
                        count2++;
                    }
                }
                System.out.println(count2);
                break;

            case "MAX_UNRELATED_PEOPLE":
                List<String> unrelatedPeople = new ArrayList<>();
                for (String code1 : citizenMap.keySet()) {
                    boolean isUnrelated = true;
                    for (String code2 : unrelatedPeople) {
                        if (isAncestor(citizenMap.get(code2), citizenMap.get(code1))) {
                            isUnrelated = false;
                            break;
                        }
                    }
                    if (isUnrelated) {
                        unrelatedPeople.add(code1);
                    }
                }
                System.out.println(unrelatedPeople.size());
                break;

            default:
                System.out.println("Invalid query: " + query[0]);
                break;
        }
    }
}

public static boolean isAncestor(Citizen ancestor, Citizen descendant) {
    while (!descendant.code.equals("0000000")) {
        descendant = citizenMap.get(descendant.fatherCode);
        if (descendant == null) {
            return false;
        }
        if (ancestor.code.equals(descendant.code)) {
            return true;
        }
    }
    return false;
}