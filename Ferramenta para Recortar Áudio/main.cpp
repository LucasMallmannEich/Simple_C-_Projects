#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <locale>

using namespace std;

struct wave_head {
    char chunkID[4];
    uint32_t tamanho;
    char format[4];
};

struct wave_sub_head {
    char subchunk1ID[4];
    uint32_t sub1_tamanho;
    uint16_t format_audio;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
};

struct wave_data_head {
    char subchunk2ID[4];
    uint32_t sub2_tamanho;
};

int main()
{
    // Disponibilizar o uso da ortografia da língua portuguesa.
    setlocale(LC_ALL, "");

    // Declaração da variável que armazena o nome do arquivo.
    string nome_arq = "";

    // Inserção do nome do arquivo por parte do usuário.
    cout << "Digite o nome do arquivo wave, sem o '.wav': ";
    cin >> nome_arq;

    // Nome do arquivo onde será gravado o trecho da música recortado.
    string nome_arq_rec = nome_arq + "_rec.wav";

    // Inserção do ".wav" ao final do nome do arquivo.
    nome_arq = nome_arq + ".wav";

    // Objeto que será utilizado para ler o arquivo.
    ifstream leitura;

    // Abertura do arquivo no formato de leitura e no formato binário.
    leitura.open(nome_arq, ios::in|ios::binary);

    // Caso o arquivo não possa ser aberto ou não exista.
    if (! leitura) {
        cout << "O arquivo não pode ser aberto." << endl;
        return -1;
    }

    // Declaração da struct que contém os dados do cabeçalho do arquivo.
    wave_head header;

    // Declaração de uma variável que irá armazenar byte por byte do arquivo.
    unsigned char byte;

    // Captação do ChunkID do arquivo.
    for(int i=0; i < 4; i++) {
        leitura >> byte;
        header.chunkID[i] = byte;
    }

    // Captação do tamanho (ChunkSize) do arquivo.
    leitura.read((char *)&header.tamanho, sizeof(header.tamanho));

    // Captação do formato do arquivo.
    for(int i=0; i < 4; i++) {
        leitura >> byte;
        header.format[i] = byte;
    }

    // Transformação dos vetores em strings.
    string chunkID = "....";
    string format = "....";
    for (int i=0; i < 4; i++) {
        chunkID[i] = header.chunkID[i];
        format[i] = header.format[i];
    }

    // Declaração da struct que contém os dados do sub-cabeçalho1 do arquivo.
    wave_sub_head sub_header1;

    // Captação dos dados do sub-cabeçalho1.
    leitura.read((char *)&sub_header1, sizeof(wave_sub_head));

    // Declaração da struct que contém os dados do cabeçalho dos dados sonoros.
    wave_data_head data_header;

    // Captação dos informações do cabeçalho dos dados sonoros.
    leitura.read((char *)&data_header, sizeof(data_header));

    // Captação dos metadados.
    char musica[22];
    leitura.seekg(-278, ios::end);
    leitura.read(musica, 22);

    char album[244];
    leitura.seekg(-256, ios::end);
    leitura.read(album, 244);

    char artista[12];
    leitura.seekg(-12, ios::end);
    leitura.read(artista, 12);

    // MENU.
    int numero=0;
    while (numero != 3) {
        // Seleção da operação que será realizada no menu.
        cout << endl << " MENU (digite um dos números):" << endl;
        cout << " 1: Exibir dados do arquivo." << endl;
        cout << " 2: Recortar um trecho de áudio do arquivo." << endl;
        cout << " 3: Sair do programa." << endl;
        cout << "DIGITE UM DOS NÚMEROS: ";
        do {
            cin >> numero;
            if (numero < 1 || numero > 3) {
                cout << "Por favor, digite novamente: ";
            }
        } while (numero < 1 || numero > 3);

        // Impressão dos dados do arquivo wave informado pelo usuário.
        if (numero == 1) {
            cout << endl << "Dados do Arquivo:" << endl;
            cout << "ID: " << chunkID << endl;
            cout << "Tamanho: " << header.tamanho << " bytes" << endl;
            cout << "Formato: " << format << endl;
            cout << "Sub ID: " << sub_header1.subchunk1ID << endl;
            cout << "Tamanho Subchunk: " << sub_header1.sub1_tamanho << endl;
            cout << "Formato de Áudio: " << sub_header1.format_audio << endl;
            cout << "Número de Canais: " << sub_header1.num_channels << endl;
            cout << "Sample Rate: " << sub_header1.sample_rate << endl;
            cout << "Byte Rate: " << sub_header1.byte_rate << endl;
            cout << "Block Align: " << sub_header1.block_align << endl;
            cout << "Bits por Amostra: " << sub_header1.bits_per_sample << endl;
            cout << "Data ID: " << data_header.subchunk2ID << endl;
            cout << "Tamanho dos Dados do Som: " << data_header.sub2_tamanho << " bytes" << endl;
            cout << "Música: " << musica << endl;
            cout << "Álbum: " << album << endl;
            cout << "Artista: " << artista << endl;
        }
        // Recorte da música.
        else if (numero == 2) {
            // Variável que armazena o tempo da música, em segundos.
            int tempo_musica = ((header.tamanho+8)/sub_header1.byte_rate);
            cout << " Tempo da Música: " << tempo_musica << " segundos." << endl;

            // Variáveis que determinam o inicio e o fim do corte, ambas em segundos.
            int inicio, fim;

            // Captação do início do corte.
            cout << "Digite o segundo em que se inicia o corte: ";
            cin >> inicio;
            while (inicio < 0 || inicio > (tempo_musica-1)) {
                cout << "Por favor, digite novamente: ";
                cin >> inicio;
            }

            // Captação do fim do corte.
            cout << "Digite o segundo em que se encerra o corte: ";
            cin >> fim;
            while (fim < inicio || fim == inicio || fim > tempo_musica) {
                cout << "Por favor, digite novamente: ";
                cin >> fim;
            }

            // Objeto que será utilizado para escrever o novo arquivo wave.
            ofstream escrita;

            // Abertura do arquivo no formato de escrita e no formato binário.
            escrita.open(nome_arq_rec, ios::out|ios::binary);

            // Caso o arquivo não possa ser aberto ou não exista.
            if (! escrita) {
                cout << "Houve um erro na criação do arquivo." << endl;
                return -1;
            }

            // Ajustando o tamanho do novo arquivo no cabeçalho e na parte dos dados sonoros.
            data_header.sub2_tamanho = (data_header.sub2_tamanho * (fim-inicio)) / tempo_musica;
            header.tamanho = data_header.sub2_tamanho+36;

            // Escrevendo os as informações do cabeçalho e sub-cabeçalhos no novo arquivo.
            escrita.write(reinterpret_cast<char*> (&header), sizeof(header));
            escrita.write(reinterpret_cast<char*> (&sub_header1), sizeof(sub_header1));
            escrita.write(reinterpret_cast<char *> (&data_header), sizeof(data_header));

            // Fecha o arquivo.
            leitura.close();

            // Abre o arquivo informado para leitura de informações binárias.
            leitura.open(nome_arq, ios::in|ios::binary);

            // Caso o arquivo não possa ser aberto ou não exista.
            if (! escrita) {
                cout << "Houve um erro na criação do arquivo." << endl;
                return -1;
            }

            // Declaração da variável que irá ler os bytes do arquivo informado.
            unsigned char byte1;

            // Laço de repetição que lê os bytes do arquivo que vem antes do início dos dados sonoros.
            // Isso serve para "ignorar" os dados sonoros que aparecem antes do início do recorte da música.
            for (int i=0; i < ((sub_header1.byte_rate*inicio)+44); i++) {
                leitura.read((char *)&byte1, sizeof(byte1));
            }

            // Laço de repetição para passar os bytes dos dados sonoros para o outro arquivo wave.
            for (int i=((sub_header1.byte_rate*inicio)+44); i < (sub_header1.byte_rate*(fim+1)); i++) {
                // Lendo os bytes dos dados da música em si.
                leitura.read((char *)&byte1, sizeof(byte1));
                // Escrevendo os bytes dos dados da música em si.
                escrita.write(reinterpret_cast<char *> (&byte1), sizeof(byte1));
            }

            // Escrita dos metadados.
            escrita.write(reinterpret_cast<char *> (&musica), sizeof(musica));
            escrita.write(reinterpret_cast<char *> (&album), sizeof(album));
            escrita.write(reinterpret_cast<char *> (&artista), sizeof(artista));

            // Fecha o arquivo.
            escrita.close();
        }
        // Encerramento do programa.
        else {
            cout << endl << "Você saiu do programa." << endl;
        }
    }

    // Fecha o arquivo.
    leitura.close();

    return 0;
}
