package cpe.datamining65;

import org.apache.spark.sql.Dataset;
import org.apache.spark.sql.Row;
import org.apache.spark.sql.SparkSession;

public class CsvToDataframeApp {
    public static void main(String[] args) {
        CsvToDataframeApp app = new CsvToDataframeApp();
        app.start();
    }
    private void start() {
        SparkSession spark = SparkSession.builder()
			.master("local")
			.appName("CSV to Dataset")
			.getOrCreate();

	spark.sparkContext().setLogLevel("ERROR");	

	Dataset<Row> df = spark.read().format("csv")
			.option("header", "true")		
			.load("data/books.csv");
	df.show();
        df.printSchema();
    }
}
