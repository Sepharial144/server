# Hibiscus
The html parser


#download postgres docker
docker pull postgres

#docker run container with port forwarding
docker run --name test_postgres -e POSTGRES_PASSWORD=postgressecret -d -p 5432:5432 postgres

#show container
docker ps -a


#connect to db
docker exec  -it {id_docker} bash
psql -U postgres

postgres=# CREATE DATABASE DataSteamProject;

#show databases
\list

\c {database}

#run our application to create products
#show tables
\d pokemon_products

#quit
\q