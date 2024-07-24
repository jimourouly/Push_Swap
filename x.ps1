# Define the OU DN
$ouDN = "OU=User,DC=test,DC=ch"

# Specify the extension attribute you're interested in
# Adjust "extensionAttributeX" to the specific attribute you need, e.g., "extensionAttribute10"
$extensionAttribute = "extensionAttributeX"

# Retrieve users, including specified properties and the extension attribute
$users = Get-ADUser -Filter * -SearchBase $ouDN -Property DisplayName, Mail, TelephoneNumber, $extensionAttribute -SearchScope OneLevel

# Prepare data for export
$dataForExport = foreach ($user in $users) {
    # Create custom object for each user with the desired structure
    [PSCustomObject]@{
        Column1 = $null # nothing
        DisplayName = $user.DisplayName
        Mail = $user.Mail
        TelephoneNumber = $user.TelephoneNumber
        Column5 = $null # nothing
        ExtensionAttribute = $user.$extensionAttribute
        Column7 = $null # nothing
        SamAccountName = $user.SamAccountName
    }
}

# Export to CSV
$dataForExport | Export-Csv -Path "ADUsersExport.csv" -NoTypeInformation

# Note: Adjust the path "ADUsersExport.csv" as needed to specify where you want the CSV file saved.
