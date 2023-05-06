import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.Charset;
import java.util.Set;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

public class test {
    public static void main(String args[]) throws IOException, ParseException {
        URL url = new URL("https://v6.exchangerate-api.com/v6/4e5b7c421edf65ee9d1c525a/latest/USD");

        InputStream is = url.openStream();
        BufferedReader bufferData = new BufferedReader(new InputStreamReader(is, Charset.forName("UTF-8")));

        StringBuilder sb = new StringBuilder();
        int cp;
        while((cp = bufferData.read()) != -1) sb.append((char) cp);

        JSONParser parser = new JSONParser();
        JSONObject data = (JSONObject) parser.parse(sb.toString());

        Set conversionRates = ((JSONObject) data.get("conversion_rates")).keySet();

        for (Object conversionRate : conversionRates) {
            System.out.println(conversionRate.toString() + " : " + ((JSONObject) data.get("conversion_rates")).get(conversionRate));
        }
    }
}
