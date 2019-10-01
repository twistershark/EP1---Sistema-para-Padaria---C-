<h2>Como utilizar o programa</h2>
<p>Antes de utilizar o software pela primeira vez, é necessário utilizar o comando <strong>make clean</strong> no terminal.</p>
<p>Após utilizar o comando acima, é necessário utilizar o comando <strong>make</strong> para que o compilador junte todos os arquivos.</p>
<p>Para executar o software é necessário digitar no terminal <strong>./bin/prog</strong></p>

<h3>Modo Venda</h3>
<p>Ao ser solicitado para digitar o CPF, o usuário do programa deve inserir apenas números.</p>
<p>Todos os arquivos de compras estão localizados na pasta ./db/compras/</p>

<h3>Modo Estoque</h3>
<p>Basta seguir as instruções presentes no programa para poder cadastrar novos produtos e/ou atualizar o estoque</p>
<p>Caso algum produto seja excluído manualmente, deve se alterar o arquivo de contadorid presente na pasta ./db/etc/, para uma unidade acima da atribuída ao último produto. </p>

<h3>Modo Recomendação</h3>
<p>Assim como no Modo Venda, o usuário deve inserir somente números no CPF.</p>
<p>É necessário que o Cliente esteja cadastrado e tenha feito ao menos uma compra na loja antes de usar o Modo Recomendação. Caso contrário, será apresentado uma mensagem de erro e o software seja encerrado</p>


