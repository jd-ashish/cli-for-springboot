import boto3

# Create an S3 client
s3 = boto3.client(
    's3',
    aws_access_key_id='KEY',
    aws_secret_access_key='SECRET'
)

filename = '/path/to/file'
bucket_name = 'BUCKET'

# Uploads the given file using a managed uploader, which will split up large
# files automatically and upload parts in parallel.
s3.upload_file(filename, bucket_name, filename)