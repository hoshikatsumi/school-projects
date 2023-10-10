#include <bits/stdc++.h>
using namespace std;

// Fungsi tanpa return point untuk swap elemen array
void bubbleSortSwapping(vector<int> &array) {
  // Variabel awal
  int n = array.size();
  // For loop untuk swap elemen array
  for (int c = 0; c < n - 1; c++) {
    if (array[c] > array[c + 1]) {
      swap(array[c], array[c + 1]);
    }
  }
}

bool bubbleSortIsSwapped(const vector<int> &array) {
  // Variabel awal
  int n = array.size();
  // For loop untuk mengecek seluruh kondisi elemen array
  for (int c = 0; c < n - 1; c++) {
    // Cek kondisi apabila array indeks c lebih daripada array indeks setelahnya dan set boolean swapped menjadi true
    if (array[c] > array[c + 1]) {
      return true;
    }
  }
  // Apabila kondisi tidak terpenuhi, return false
  return false;
}

// Fungsi bubble sort untuk mengurutkan data tanpa return point
void bubbleSort(vector<int> &array) {
  // Variabel awal
  int n = array.size();
  bool swapped;
  // Do ... while loop untuk swap elemen array
  do {
    swapped = false;
    bubbleSortSwapping(array);
    swapped = bubbleSortIsSwapped(array);
  } while (swapped);
}

// Fungsi perhitungan median data dengan return point ke double median di fungsi utama
double perhitunganMedian(const vector<int> &beratBadanGabungan) {
  // Variabel awal
  vector<int> sortedArray = beratBadanGabungan;
  bubbleSort(sortedArray); // Sorting vector
  int n = sortedArray.size(); // Tentukan panjang vector
  // Jika elemen vector berjumlah ganjil, kembalikan vector sortedArray indeks tengah
  if (n % 2 != 0) {
    return (double)sortedArray[n / 2];
  }
  // Return point apabila elemen vector tidak berjumlah ganjil
  return (double)(sortedArray[n / 2 - 1] + sortedArray[n / 2]) / 2;
}

// Fungsi perhitungan mean data dengan return point ke double mean di fungsi utama
double perhitunganMean(const vector<int> &beratBadanGabungan) {
  // Variabel awal
  vector<int> array = beratBadanGabungan;
  bubbleSort(array); // Sorting vector
  int sum = 0;
  // For loop untuk menghitung mean
  for (int num : array) {
    sum += num;
  }
  // Kembalikan hasil perhitungan
  return (double)sum / array.size();
}

// Fungsi perhitungan modus data dengan return point ke double modus di fungsi utama
vector<int> perhitunganModus(const vector<int> &beratBadanGabungan) {
  // Variabel awal
  unordered_map<int, int> frekuensi;
  vector<int> modus;
  // Menghitung frekuensi kemunculan setiap elemen dalam vector
  for (int num : beratBadanGabungan) {
    frekuensi[num]++;
  }
  // Mencari frekuensi maksimum dari data
  int frekuensiMaksimum = 0;
  for (const auto &entry : frekuensi) {
    if (entry.second > frekuensiMaksimum) {
      frekuensiMaksimum = entry.second;
    }
  }
  // Memasukkan semua elemen yang memiliki frekuensi maksimum ke dalam vektor modus
  for (const auto &entry : frekuensi) {
    if (entry.second == frekuensiMaksimum) {
      modus.push_back(entry.first);
    }
  }
  // Mengembalikan vektor modus yang berisi modus dari vector
  return modus;
}

// Fungsi penggabungan data dengan return point ke vector beratBadanGabungan di fungsi utama
vector<int> penggabunganData(const vector<int> &beratBadanGuruTTDKG, const vector<int> &beratBadanMuridTTDKG, const vector<int> &beratBadanStafKG, const vector<int> &beratBadanMuridKG) {
  // Initialisasi variabel hasil
  vector<int> beratBadanGabungan;
  // Penggabungan data
  beratBadanGabungan.insert(beratBadanGabungan.end(), beratBadanGuruTTDKG.begin(), beratBadanGuruTTDKG.end());
  beratBadanGabungan.insert(beratBadanGabungan.end(), beratBadanMuridTTDKG.begin(), beratBadanMuridTTDKG.end());
  beratBadanGabungan.insert(beratBadanGabungan.end(), beratBadanStafKG.begin(), beratBadanStafKG.end());
  beratBadanGabungan.insert(beratBadanGabungan.end(), beratBadanMuridKG.begin(), beratBadanMuridKG.end());
  // Return variabel hasil
  return beratBadanGabungan;
}

// Fungsi perhitungan jangkauan data dengan return point ke fungsi utama
double perhitunganJangkauanData(vector<int> &array) {
  double n = array.size();
  double xMaks = array[n-1];
  double xMins = array[0];
  double jangkauanData = xMaks - xMins;
  return jangkauanData;
}

// Fungsi perhitungan banyak kelas interval
double perhitunganKelasInterval(vector<int> &array) {
  double n = array.size();
  double logarithm = log10(n);
  double result = (3.3 * logarithm) + 1;
  double resultRounded = round(result);
  return resultRounded;
}

// Fungsi perhitungan panjang kelas interval
double perhitunganPanjangKelasInterval(double &jangkauanData, double &banyakKelasInterval) {
  double result = jangkauanData / banyakKelasInterval;
  return result;
}

// Fungsi print
void print(vector<int> &beratBadanGabungan, vector<int> &beratBadanGabunganSorted, double &median, double &mean, vector<int> &modus, double &jangkauanData, double &banyakKelasInterval, double &panjangKelasInterval) {
  // Print vector beratBadanGabungan
  int beratBadanGabunganSize = beratBadanGabungan.size();
  cout << "Berat badan gabungan:" << " ";
  for (int c = 0; c < beratBadanGabunganSize; c++) {
    if (c != beratBadanGabunganSize - 1) {
      cout << beratBadanGabungan[c] << " ";
    } else {
      cout << beratBadanGabungan[c] << "\n";
    }
  }
  // Print vector beratBadanGabunganSorted
  int beratBadanGabunganSortedSize = beratBadanGabunganSorted.size();
  cout << "Berat badan gabungan (sorted):" << " ";
  for (int c = 0; c < beratBadanGabunganSortedSize; c++) {
    if (c != beratBadanGabunganSortedSize - 1) {
      cout << beratBadanGabunganSorted[c] << " ";
    } else {
      cout << beratBadanGabunganSorted[c] << "\n";
    }
  }
  // Print jumlah data
  cout << "Range data: " << beratBadanGabunganSize << "\n";
  // Print median
  cout << "Median: " << median << "\n";
  // Print mean
  cout << "Mean: " << mean << "\n";
  // Print modus
  int modusSize = modus.size();
  cout << "Modus:" << " ";
  for (int c = 0; c < modusSize; c++) {
    if (c != modusSize - 1) {
      cout << modus[c] << " ";
    } else {
      cout << modus[c] << "\n";
    }
  }
  // Print jangkauan data
  cout << "Jangkauan data: " << jangkauanData << "\n";
  // Print banyak kelas interval
  cout << "Banyak kelas interval: " << banyakKelasInterval << "\n";
  // Print panjang kelas interval
  cout << "Panjang kelas interval: " << panjangKelasInterval << "\n";
}

// Fungsi utama
int main(int argc, char** argv) {
  // Data awal
  vector<int> beratBadanGuruTTDKG = {57, 49, 43, 50, 50, 55};
  vector<int> beratBadanMuridTTDKG = {30, 41, 53, 48, 45, 44, 41, 50, 30, 82};
  vector<int> beratBadanStafKG = {50, 53, 65, 77, 63, 45, 80, 75, 40, 58, 58};
  vector<int> beratBadanMuridKG = {
    48, 59, 45, 37, 40, 53, 39, 40, 60, 80, 79, 56, 45, 64, 30, 45,
    60, 45, 40, 75, 59, 43, 40, 60, 52, 40, 43, 40, 25, 78, 68, 70,
    52, 49, 37, 52, 38, 79, 58, 54, 45, 63, 68, 80, 88, 58, 65, 42,
    68, 52, 46, 50, 43, 41, 45, 49, 35, 41
  };
  // Data gabungan
  vector<int> beratBadanGabungan = penggabunganData(beratBadanGuruTTDKG, beratBadanMuridTTDKG, beratBadanStafKG, beratBadanMuridKG);
  // Median
  double median = perhitunganMedian(beratBadanGabungan);
  // Mean
  double mean = perhitunganMean(beratBadanGabungan);
  // Modus
  vector<int> modus = perhitunganModus(beratBadanGabungan);
  // Data gabungan sorted
  vector<int> beratBadanGabunganSorted = beratBadanGabungan;
  bubbleSort(beratBadanGabunganSorted);
  // Frekuensi setiap kelas
  double jangkauanData = perhitunganJangkauanData(beratBadanGabunganSorted);
  // Banyak kelas interval
  double banyakKelasInterval = perhitunganKelasInterval(beratBadanGabunganSorted);
  // Panjang kelas interval
  double panjangKelasInterval = perhitunganPanjangKelasInterval(jangkauanData, banyakKelasInterval);
  // Fungsi print data
  print(beratBadanGabungan, beratBadanGabunganSorted, median, mean, modus, jangkauanData, banyakKelasInterval, panjangKelasInterval);
  // Exit
  return 0;
}
